#include <iostream>
#include <vector>

void threeWayPartition(std::vector<int> &nums, int left, int right, int &lt,
                       int &rt, int &pivot) {
  pivot = nums[right];
  lt = left;
  int mid = left;
  rt = right;
  while (mid <= rt) {
    if (nums[mid] < pivot) {
      std::swap(nums[mid], nums[lt]);
      ++mid;
      ++lt;
    } else if (nums[mid] > pivot) {
      std::swap(nums[mid], nums[rt]);
      --rt;
    } else {
      ++mid;
    }
  }
}

int main() {
  std::vector<int> nums{50, 25, 76, 38, 19, 58, 29, 88, 44, 22, 11, 34};
  int m = static_cast<int>(nums.size());
  int left = 0;
  int right = m - 1;
  int lt = left;
  int rt = right;
  int pivot = 0;
  threeWayPartition(nums, left, right, lt, rt, pivot);
  for (int i : nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::cout << "pivot is " << pivot << std::endl;
  std::cout << "left bound at " << lt << std::endl;
  std::cout << "right bound at " << rt << std::endl;
  return 0;
}
