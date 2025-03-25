#include <iostream>

class CA {
public:
  void func1(void) { std::cout << "func1 in CA" << std::endl; }

  virtual void func2(void) { std::cout << "func2 in CA" << std::endl; }
};

class CB : public CA {
public:
  void func1(void) { std::cout << "func1 in CB" << std::endl; }
  void func2(void) override {
    // Specify override to tell compiler 'func2' is
    // an override function of 'func2' in CA class
    std::cout << "func2 in CB" << std::endl;
  }
};

int main(int, char *[]) {
  CA *objA = new CA();
  CB *objB = new CB();
  objA->func1();
  objA->func2();
  objB->func1();
  objB->func2();
  CA *objB2 = objB;
  objB2->func1();
  objB2->func2();
  return 0;
}
