#include <iostream>
#include <thread>

using namespace std;

void threadFunc(void) { cout << "this is a thread func" << endl; }

int main() {
  thread thread_1(threadFunc);
  thread_1.join();
  exit(EXIT_SUCCESS);
}
