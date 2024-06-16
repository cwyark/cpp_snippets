#include <iostream>
#include <memory>

class Base
{
  std::string name;

public:
  std::string getName() {
    return name;
  }
  void setName(std::string name)
  {
    name = name;
  };
};

int main(int, char *[])
{
  std::unique_ptr<Base> foo_1 = std::make_unique<Base>();
  foo_1->setName("foo_1");
  std::cout << foo_1->getName() << std::endl;
}
