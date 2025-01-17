#include <iostream>

struct A {
  virtual ~A() {}
};

struct B : A {};

typedef struct Foo {
  int a = 0;
  int b = 1;
  int c = 2;
} Foo_t;

struct Bar : public Foo {
  int d = 10;
};

int main(int, char *[]) {
  A *a = new A();

  B *b = dynamic_cast<B *>(a);
  if (b) {
    std::cout << "b has value" << std::endl;
  } else {
    std::cout << "no value" << std::endl;
  }
  struct Foo foo;
  std::cout << foo.a << std::endl;
  struct Bar bar;
  std::cout << bar.b << std::endl;
  struct Foo *foo2 = dynamic_cast<struct Foo *>(&bar);
  std::cout << foo2->c << std::endl;
  // struct Bar * bar2  = dynamic_cast<struct Bar*>(&foo);
  // std::cout << bar2->d << std::endl;
}
