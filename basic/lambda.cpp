#include <iostream>

int main() {
  auto helloworld = []() { return "hello world!"; };
  std::cout << helloworld() << std::endl;
  return 0;
}
