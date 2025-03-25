#include <iostream>
#include <queue>

int main(int argc, char *argv[]) {
  std::queue<int> q;
  q.push(10);
  std::cout << q.front() << std::endl;
  return 0;
}
