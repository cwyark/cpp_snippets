#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> sharedPtr(new int(42), [](int *p) {
    std::cout << "customer deleter" << std::endl;
    delete p;
  });
  std::cout << *sharedPtr << std::endl;
}
