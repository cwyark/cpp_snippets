#include <chrono>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

int threadFunc(int interval) {
  this_thread::sleep_for(chrono::seconds(interval));
  return interval;
}

int main() {
  future<int> fuRes1 = async(launch::async, threadFunc, 1);
  future<int> fuRes2 = async(launch::async, threadFunc, 2);
  auto tpStart = chrono::high_resolution_clock::now();
  int result = fuRes1.get() + fuRes2.get();
  auto tpEnd = chrono::high_resolution_clock::now();
  auto duration = tpEnd - tpStart;
  cout << "result = " << result << ", duration = "
       << chrono::duration_cast<chrono::milliseconds>(duration).count() << " ms"
       << endl;
  exit(EXIT_SUCCESS);
}
