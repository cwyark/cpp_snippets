#include <iostream>

class Base {
public:
  Base(int id) : id_(id) { std::cout << "this is constructor" << std::endl; }
  Base &foo() {
    std::cout << "foo" << std::endl;
    return *this;
  }

private:
  int id_;
};

class Derived : public Base {

public:
  Derived &operator=(Base &object) { return static_cast<Derived &>(*this); }

  Derived &bar() {
    std::cout << "bar " << std::endl;
    return *this;
  }
};

int main(int, char *[]) {
  Derived *derived;
  // d.foo().bar();
}
