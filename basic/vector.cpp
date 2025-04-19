#include <iostream>
#include <vector>

using namespace ::std;

int main() {
  vector<int> arr{1, 2, 3, 4};
  for (int i = 0; i < arr.size(); ++i) {
    if (i == 2) {
      arr.erase(std::remove(arr.begin(), arr.end(), i));
    }
    std::cout << arr[i] << std::endl;
  }

  cout << "perform pop_back" << endl;
  arr.pop_back();
  for (auto &e : arr) {
    cout << e << endl;
  }
}
