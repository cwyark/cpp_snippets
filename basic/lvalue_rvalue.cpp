#include <iostream>

int global_val = 20;

const int &i = 345;
int &global_ref = global_val;

// this will return global_val lvalue reference
int &foo() { return global_val; }

int main() {
  foo() = 10;
  std::cout << global_val << std::endl;
  std::cout << i << std::endl;
  if (&global_ref == &global_val) {
    std::cout << "same address" << std::endl;
  }
}
