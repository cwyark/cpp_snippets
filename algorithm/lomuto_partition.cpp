#include <iostream>
#include <vector>

using namespace std;

// range definition:
// [left, i) <= pivot
// [i, j) > pivot
// [j, right) not yet processed
int lomuto(vector<int> &nums, int left, int right) {
  int pivot = nums[right];
  int i = left;
  for (int j = left; j < right; ++j) {
    if (nums[j] <= pivot) {
      swap(nums[i], nums[j]);
      ++i;
    }
  }
  swap(nums[i], nums[right]);
  return i;
}

int randomPivotLomuto(vector<int> &nums, int left, int right) {
  int pivotIdx = left + std::rand() % (right - left + 1);
  swap(nums[right], nums[pivotIdx]);
  int pivot = nums[right];
  int i = left;
  for (int j = left; j < right; ++j) {
    if (nums[j] <= pivot) {
      swap(nums[j], nums[right]);
      ++i;
    }
  }
  swap(nums[i], nums[right]);
  return i;
}

int main() {
  vector<int> nums{50, 25, 76, 38, 19, 58, 29, 88, 44, 22, 11, 34};
  int m = static_cast<int>(nums.size());
  cout << "nums size:" << m << endl;
  int start = 0;
  int end = m - 1;
  int pivot = lomuto(nums, start, end);
  for (int i : nums) {
    cout << i << " ";
  }
  cout << endl;
  cout << "pivot: " << pivot << endl;
  return 0;
}
