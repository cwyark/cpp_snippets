#include <iostream>
#include <vector>

using namespace std;

// hoare partition on [left, right] 
// reorders elements around a pivot chosen from this range and returns and index p
// such that:
// nums[k] <= pivot value for all k in [left, p]
// nums[k] >= pivot value for all k in [p + 1, right]
int hoare(vector<int> &nums, int left, int right) {
  // use middle point as the pivot
  if (left > right) return left - 1;
  const int pivot = nums[left + (right - left) / 2];
  int i = left - 1;
  int j = right + 1;
  while (true) {
    do {
      ++i;
    } while (nums[i] < pivot);
    do {
      --j;
    } while (nums[j] > pivot);
    if (i >= j)
      return j;
    swap(nums[i], nums[j]);
  }
  // should never enter here.
  return -1;
}

int main() {
  vector<int> nums{50, 25, 76, 38, 19, 58, 29, 88, 44, 22, 11, 34};
  int m = static_cast<int>(nums.size());
  int start = 0;
  int end = m - 1;
  cout << "nums size: " << m << endl;
  int pivot = hoare(nums, start, end);
  for (int i : nums) {
    cout << i << " ";
  }
  cout << endl;
  cout << "pivot at " << pivot << endl;
  return 0;
}

