#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<int> uniquePtr(new int(42));
  std::cout << "Value: " << *uniquePtr << std::endl;
  std::unique_ptr<int> uniquePtr_new = std::move(uniquePtr);
  if (!uniquePtr) {
    std::cout << "uniquePtr now is null" << std::endl;
  }
  std::cout << "uniquePtr_new now is " << *uniquePtr_new << std::endl;
  return 0;
}
