#include <iostream>

int global_val = 20;

const int &i = 345;
int &global_ref = global_val;

// this will return global_val lvalue reference
int &foo() { return global_val; }

void bar(int &c) { c += 1; }

int main() {
  int c = 0;
  foo() = 10;
  std::cout << global_val << std::endl;
  std::cout << i << std::endl;
  if (&global_ref == &global_val) {
    std::cout << "same address" << std::endl;
  }
  std::cout << "c is " << c << std::endl;
  bar(c);
  std::cout << "c is being modified to " << c << " after bar" << std::endl;
}
