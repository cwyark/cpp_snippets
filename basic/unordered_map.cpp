#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
  unordered_map<int, int> map;
  map[10] = 1;
  map[20] = 2;
  for (auto [k, v] : map) {
    cout << k << endl;
  }
  return 0;
}
