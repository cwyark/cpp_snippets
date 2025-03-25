#include <iostream>

class Bar {
public:
  Bar() { std::cout << "init bar" << std::endl; };
  void bark() { std::cout << "bark!" << std::endl; };
};

class Foo {
public:
  void reference_method(Bar &bar_) { bar_.bark(); }
  void pointer_method(Bar *bar) { bar->bark(); }
};

int main(int, char *[]) {
  Foo f;
  Bar b;
  f.reference_method(b);
  f.pointer_method(&b);
  return 0;
}
