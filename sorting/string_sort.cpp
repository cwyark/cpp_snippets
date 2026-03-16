#include <iostream>
#include <string>

int main() {
  std::string a = "bbaccd";
  std::string b = a;
  sort(b.begin(), b.end());
  std::cout << b << std::endl;
  return 0;
}
