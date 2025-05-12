
#include <iostream>
#include <unordered_set>

int main() {
  std::unordered_set<int> set;
  set.insert(0);
  std::cout << set.size() << std::endl;
  if (set.count(0) > 0) {
    std::cout << "0 exists" << std::endl;
  }
  return 0;
}
