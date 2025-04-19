
#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<int> set;
  set.insert(0);
  std::cout << set.size() << std::endl;
}
