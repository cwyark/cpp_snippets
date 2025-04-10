#include <iostream>
#include <mutex>
#include <thread>

static int counter = 0;
static std::mutex mutex;

void thread_A(void *arg) {
  mutex.lock();
  std::cout << "counter increment" << std::endl;
  counter++;
  mutex.unlock();
}

void thread_B(void *arg) {
  mutex.lock();
  std::cout << "counter decrement" << std::endl;
  counter--;
  mutex.unlock();
}

int main() {
  std::thread t1(thread_A, nullptr);
  std::thread t2(thread_B, nullptr);
  t1.join();
  t2.join();
  std::cout << "final counter value is " << counter << std::endl;
  return 0;
}
