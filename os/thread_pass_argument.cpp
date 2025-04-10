#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void threadFunc(int n, int *N) { *N = n + 1; }

int main() {
  int n = 10;
  int N = 0;
  thread thread_1(threadFunc, n, &N);
  thread_1.join();
  cout << N << endl;
  exit(EXIT_SUCCESS);
}
