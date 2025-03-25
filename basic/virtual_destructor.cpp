#include <iostream>

class BaseClass {
public:
  BaseClass() { std::cout << "BaseClass constructor" << std::endl; }

  virtual ~BaseClass() {
    std::cout << "virtual BaseClass destructor" << std::endl;
  }

  virtual void foo(void) { std::cout << "virtual BaseClass foo" << std::endl; }
};

class DerivedClass : public BaseClass {
public:
  DerivedClass() { std::cout << "DerivedClass constructor" << std::endl; }
  ~DerivedClass() { std::cout << "DerivedClass destructor" << std::endl; }

  void foo(void) override {
    BaseClass::foo();
    std::cout << "DerivedClass foo" << std::endl;
  }
};

int main(int, char *[]) {
  // BaseClass bc;
  // bc.foo();
  // std::cout << "------------" << std::endl;
  // DerivedClass dc;
  // dc.foo();
  // std::cout << "------------" << std::endl;
  // BaseClass *bc_duplicated = &dc;
  // bc_duplicated->foo();
  // std::cout << "------------" << std::endl;
  DerivedClass dc;
  dc.foo();
  return 0;
}
