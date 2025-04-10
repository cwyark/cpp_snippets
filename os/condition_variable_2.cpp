#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex g_mutex;
condition_variable g_condition;

void threadFunc(void) {
  cout << this_thread::get_id() << " thread started" << endl;
  unique_lock<mutex> lock(g_mutex);
  g_condition.wait_for(lock, chrono::seconds(2));
  cout << this_thread::get_id() << " thread ended." << endl;
}

int main() {
  thread t1(threadFunc);
  t1.join();
  exit(EXIT_SUCCESS);
}
