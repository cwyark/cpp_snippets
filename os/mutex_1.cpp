#include <iostream>
#include <mutex>
#include <thread>

int counter = 0;
std::mutex mutex;

void thread_A(void) {
  mutex.lock();
  std::cout << "counter increment" << std::endl;
  counter++;
  mutex.unlock();
}

void thread_B(void) {
  mutex.lock();
  std::cout << "counter decrement" << std::endl;
  counter--;
  mutex.unlock();
}

int main() {
  std::thread t1(thread_A);
  std::thread t2(thread_B);
  t1.join();
  t2.join();
  std::cout << "final counter value is " << counter << std::endl;
  return 0;
}
