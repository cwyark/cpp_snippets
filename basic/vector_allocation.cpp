#include <iostream>
#include <vector>

static int n_allocation = 0;

void *operator new(size_t size) {
  ++n_allocation;
  std::cout << "allocated " << size << " bytes" << std::endl;
  return malloc(size);
}

void printVector(std::vector<int> data) {
  for (auto &i : data) {
    std::cout << i << std::endl;
  }
}

void printVectorReference(std::vector<int> &data) {
  for (auto &i : data) {
    std::cout << i << std::endl;
  }
}

int main() {
  std::vector<int> data = {1, 2, 3, 4, 5};
  std::cout << n_allocation << " allocations" << std::endl;
  printVector(data);
  std::cout << n_allocation << " allocations" << std::endl;
  printVectorReference(data);
  std::cout << n_allocation << " allocations" << std::endl;
  return 0;
}
