#include <iostream>

enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main() {
  Day today = Sunday;
  std::cout << "today is " << today << std::endl;
}
