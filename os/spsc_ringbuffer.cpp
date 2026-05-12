#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

template <typename T> class SPSCRingBuffer {
public:
  SPSCRingBuffer(size_t capacity = 2) : capacity(capacity) {
    buffer.resize(capacity);
  }

  bool isEmpty() const {
    std::lock_guard<std::mutex> lock(m);
    return empty_unlock();
  }

  bool isFull() const {
    std::lock_guard<std::mutex> lock(m);
    return full_unlock();
  }

  bool push(const T &val) {
    std::unique_lock<std::mutex> lock(m);
    if (full_unlock())
      return false;
    buffer[tail] = val;
    tail = next(tail);
    return true;
  }

  bool pop(T &val) {
    std::unique_lock<std::mutex> lock(m);
    if (empty_unlock())
      return false;
    val = buffer[head];
    head = next(head);
    return true;
  }

private:
  std::vector<T> buffer;
  size_t capacity;
  size_t head{0};
  size_t tail{0};
  mutable std::mutex m;
  size_t next(size_t index) const { return (index + 1) % capacity; }
  bool empty_unlock() const { return head == tail; }
  bool full_unlock() const { return next(tail) == head; }
};

int main() {
  constexpr size_t capacity = 1000;
  constexpr int kCount = 10000000;
  std::atomic<bool> producerDone{false};
  int consumedCount = 0;
  SPSCRingBuffer<int> rb(capacity);

  std::thread producer([&]() {
    for (int i = 0; i < kCount;) {
      if (rb.push(i)) {
        ++i;
      } else {
        std::this_thread::yield();
      }
    }
    producerDone.store(true, std::memory_order_release);
  });

  std::thread consumer([&]() {
    int expect = 0;
    int value = 0;
    while (expect < kCount) {
      if (rb.pop(value)) {
        if (value != expect) {
          std::cout << "value unmatch" << std::endl;
          break;
        }
        ++expect;
        ++consumedCount;
      } else if (producerDone.load(std::memory_order_acquire)) {
        break;
      } else {
        std::this_thread::yield();
      }
    }
  });

  producer.join();
  consumer.join();
  std::cout << "consumed: " << consumedCount << std::endl;
  return 0;
}
