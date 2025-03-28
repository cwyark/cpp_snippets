#include <iostream>
#include <memory>

class B;

class A {
public:
  std::shared_ptr<B> instance;
  ~A() { std::cout << "A destroied" << std::endl; }
};

class B {
public:
  std::weak_ptr<A> instance;
  ~B() { std::cout << "B destroied" << std::endl; }
};

int main() {
  std::shared_ptr<A> ptrA(new A());
  std::shared_ptr<B> ptrB(new B());

  ptrA->instance = ptrB;
  ptrB->instance = ptrA;

  return 0;
}
