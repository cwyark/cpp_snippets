#include <atomic>
#include <csignal>
#include <iostream>
#include <thread>
#include <vector>

std::atomic<bool> shouldStop = false;

// This file implement a lock-free ring buffer.
// For the lock-free ring buffer single producer and single consumer.
template <typename T> class SPSCRingBuffer {
public:
  // basic ring buffer operations:
  // 1. push : push to the tail.
  // 2. pop : pop from the head.
  // 3. check empty: when head == tail.
  // 4. check full. (tail + 1) % capacity == head
  // definition:
  // head: points to the next item to read.
  // tail: point to the next item to write.
  // use std::vector is better , because it owns a continious memory.
  SPSCRingBuffer(size_t capacity = 2) : capacity(capacity), head(0), tail(0) {
    buffer.resize(capacity);
  }

  bool isFull() const {
    auto nextTail = next(tail.load(std::memory_order_relaxed));
    return nextTail == head.load(std::memory_order_acquire);
  }

  bool isEmpty() const {
    return head.load(std::memory_order_acquire) ==
           tail.load(std::memory_order_acquire);
  }

  // push function is always used by producer.
  bool push(const T &value) {
    auto currentTail = tail.load(std::memory_order_relaxed);
    auto nextTail = next(currentTail);
    if (nextTail == head.load(std::memory_order_acquire))
      return false;

    buffer[currentTail] = value;
    tail = (tail + 1) % capacity;
    tail.store(nextTail, std::memory_order_release);
    return true;
  }

  // pop function is always used by consumer.
  bool pop(T &out) {
    auto currentHead = head.load(std::memory_order_relaxed);
    if (currentHead == tail.load(std::memory_order_acquire))
      return false;
    out = buffer[currentHead];
    head = (head + 1) % capacity;
    head.store(next(currentHead), std::memory_order_release);
    return true;
  }

private:
  std::vector<T> buffer;
  // consumer owned index.
  std::atomic<size_t> head;
  // producer owned index.
  std::atomic<size_t> tail;
  size_t capacity;
  size_t next(size_t index) const { return (index + 1) % capacity; }
};

int main() {
  constexpr size_t capacity = 1000;
  constexpr int kCount = 10000000;

  std::atomic<bool> producerDone{false};
  std::atomic<int> consumerCount{0};
  std::atomic<bool> ok{true};

  SPSCRingBuffer<int> rg(capacity);

  std::thread producer([&]() {
    for (int i = 0; i < kCount;) {
      if (rg.push(i)) {
        ++i;
      } else {
        std::this_thread::yield();
      }
    }
    producerDone.store(true, std::memory_order_release);
  });

  std::thread consumer([&]() {
    int expected = 0;
    int value = 0;
    while (expected < kCount) {
      if (rg.pop(value)) {
        if (value != expected) {
          std::cerr << "Mismatch: expected " << expected << ", got " << value
                    << std::endl;
          ok.store(false, std::memory_order_release);
          return;
        }
        ++expected;
        consumerCount.fetch_add(1, std::memory_order_relaxed);
      } else if (producerDone.load(std::memory_order_acquire)) {
        std::this_thread::yield();
      } else {
        std::this_thread::yield();
      }
    }
  });

  producer.join();
  consumer.join();
  std::cout << "consumed: " << consumerCount.load() << std::endl;
  return ok.load() ? 0 : 1;
}
