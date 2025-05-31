#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

class MutexQueue {
private:
  std::queue<int> _queue;
  std::mutex _mutex;

public:
  void lock() { _mutex.lock(); }

  void unlock() { _mutex.unlock(); }

  int pop() {
    int front = _queue.front();
    _queue.pop();
    return front;
  }

  void push(int value) { _queue.push(value); }
};

MutexQueue mqA;
MutexQueue mqB;

void fromAtoBAtomic(void) {
  mqA.lock();
  mqB.lock();
  int value = mqA.pop();
  mqB.push(value);
  std::cout << "value " << value << std::endl;
  mqB.unlock();
  mqA.unlock();
}

int main() {
  mqA.push(1);
  std::thread _thread(fromAtoBAtomic);
  _thread.join();
  return 0;
}
