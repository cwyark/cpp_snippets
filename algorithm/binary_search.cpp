#include <iostream>
#include <vector>

using namespace std;

int findIndexOfTarget(const std::vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;
  while (left <= right) {
    int middle = left + (right - left) / 2; // use this to prevents overflow
    if (target == arr[middle]) {
      return middle;
    } else if (target > arr[middle]) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return -1;
}

int main() {
  std::vector<int> array{3, 4, 5, 6, 7};
  int index = findIndexOfTarget(array, 5);
  cout << "index is " << index << endl;
  return 0;
}
