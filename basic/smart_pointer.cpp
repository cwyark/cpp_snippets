#include <iostream>
#include <memory>

class Base {
  std::string name;

public:
  std::string getName() { return name; }
  void setName(std::string name) { name = name; };
};

int main(int, char *[]) {
  std::shared_ptr<Base> foo_1 = std::make_shared<Base>();
  foo_1->setName("foo_1");
  std::cout << foo_1->getName() << std::endl;
}
