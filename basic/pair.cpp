#include <iostream>

int main() {
  std::pair<int, int> _pair(10, 10);
  std::cout << "pair left is " << _pair.first << "\n";
  std::cout << "pair right is " << _pair.second << "\n";
  return 0;
}
