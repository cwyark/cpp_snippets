#include <iostream>

class Shape {
public:
  virtual int area() {}
};

class Circle : public Shape {
private:
  int radius = 5;

public:
  int area() override { return radius * radius; }
};

class Retangle : public Shape {
private:
  int height = 10;
  int width = 5;

public:
  int area() override { return height * width; }
};

int main() {
  Shape *circle = new Circle();
  Shape *retangle = new Retangle();
  std::cout << circle->area() << std::endl;
  std::cout << retangle->area() << std::endl;
  return 0;
}
