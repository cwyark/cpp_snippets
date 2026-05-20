#include <vector>
// a thread-safe Queue
// basic functions:
// 1. push (push value to queue)
// 2. pop (pop value from the queue)
// 3. isFull (check the queue is full)
// 4. isEmpty (check the queue is empty)
template<typename T>
class SPSCQueue {
public:
  SPSCQueue(size_t queue_size) : queue_size(queue_size) {
    buffer.resize(queue_size);
  };
  bool push(T &value) {
    
  }

  bool pop(T &value) {
  }

  bool isFull() {
  }

  bool isEmpty() {
  }

private:
  int queue_size = 1;
  std::vector<T> buffer;
};

// SPSC shared a single queue.
int main() {}
