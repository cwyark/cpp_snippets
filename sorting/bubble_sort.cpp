

#include <iostream>
#include <vector>

class BubbleSort {
public:
  void sort(std::vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
      bool swapped = false;

      for (int j = 0; j < n - i - 1; ++j) {
        if (arr[j] > arr[j + 1]) {
          std::swap(arr[j], arr[j + 1]);
          swapped = true;
        }
      }

      // If no two elements were swapped by inner loop, then break
      if (!swapped)
        break;
    }
  }

  void print(const std::vector<int> &arr) {
    for (auto i : arr)
      std::cout << i << " ";
    std::cout << std::endl;
  }
};

int main(int argc, char *args[]) {
  std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  BubbleSort bs = BubbleSort();
  bs.sort(arr);
  bs.print(arr);
}
