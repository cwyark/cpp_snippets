#include <queue>
#include <vector>
#include <iostream>

// min heap comparator
struct Cmp {
  bool operator()(const std::vector<int> &a, const std::vector<int> &b) const {
    return a[0] > b[0];
  }
};

int main() {
  std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Cmp> pq;
  pq.push({5, 100});
  pq.push({1, 200});
  auto v = pq.top();
  std::cout << v[0] << std::endl;
  return 0;
}
