#include <iostream>

class CommandInterface
{
public:
  virtual ~CommandInterface() {};
  virtual void execute(void) = 0;
};

class Light
{
public:
  void on(void)
  {
    std::cout << "light on" << std::endl;
  }
};

// Command pattern
class LightOnCommand : public CommandInterface
{
  Light light;

public:
  LightOnCommand(Light light)
      : light(light) {};
  void execute(void) override
  // specify light to make sure we have override the virtual function
  {
    std::cout << "LightOnCommand->execute()" << std::endl;
    light.on();
  }
};

class Controller
{
};

int main(int, char **)
{
  Controller controller;
  return 0;
}
