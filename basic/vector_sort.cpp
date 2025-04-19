#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int>> arr{{1, 10}, {2, 11}, {3, 34}};
  for (auto &v : arr) {
    std::cout << v[0] << " " << v[1] << std::endl;
  }
  std::sort(arr.begin(), arr.end());
  std::cout << "after sort" << std::endl;
  for (auto &v : arr) {
    std::cout << v[0] << " " << v[1] << std::endl;
  }

  // use lambda
  std::sort(arr.begin(), arr.end(),
            [](const std::vector<int> &a, const std::vector<int> &b) {
              return a[1] > b[0];
            });

  for (auto &v : arr) {
    std::cout << v[0] << " " << v[1] << std::endl;
  }

  return 0;
}
