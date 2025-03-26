#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> sharedPtr = std::make_shared<int>(10);
  std::cout << "sharedPtr is " << *sharedPtr << std::endl;
  {
    std::shared_ptr<int> scopePtr = sharedPtr;
    std::cout << "scopePtr is " << *scopePtr << std::endl;
  }
  return 0;
}
