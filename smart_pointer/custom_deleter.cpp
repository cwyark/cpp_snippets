#include <iostream>

void customDeleter(int *p) {
  std::cout << "customerDeleter" << std::endl;
  delete p;
}

int main() {
  std::shared_ptr<int> sharedPtr(new int(42), customDeleter);
  std::cout << "Value: " << *sharedPtr << std::endl;
  sharedPtr.reset();
  return 0;
}
