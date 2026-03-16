#include <variant>
#include <vector>
#include <iostream>

int main() {
  using VariantType = std::variant<int, std::nullptr_t>;
  std::vector<VariantType> v;
  v.push_back(10);
  v.push_back(nullptr);
  for (auto& e : v) {
  }
  return 0;
}
