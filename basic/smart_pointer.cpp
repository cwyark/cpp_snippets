#include <iostream>
#include <memory>

class Foo
{
  std::string name;
  public:
    std::string getName();
    void setName(std::string name);
};

int main(int, char* [])
{
  std::unique_ptr<Foo> foo_1 = std::make_unique<Foo>();
  foo_1->setName("foo_1");
  //std::cout << foo_1->getName() << std::endl;
}
