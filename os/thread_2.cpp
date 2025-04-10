#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex g_mutex;

void threadFunc() {
  g_mutex.lock();
  cout << this_thread::get_id() << endl;
  g_mutex.unlock();
}

int main() {
  thread thread_1(threadFunc);
  thread thread_2(threadFunc);
  cout << "this is main thread" << endl;
  thread_1.join();
  thread_2.join();
  exit(EXIT_SUCCESS);
}
