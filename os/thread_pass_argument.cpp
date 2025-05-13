#include <iostream>
#include <thread>

void threadFunc(int n, int *N) { *N = n + 1; }

int main() {
  int n = 10;
  int N = 0;
  std::thread thread_1(threadFunc, n, &N);
  thread_1.join();
  std::cout << N << std::endl;
  return 0;
}
