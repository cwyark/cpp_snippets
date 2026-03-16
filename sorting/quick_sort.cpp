#include <iostream>
#include <vector>

using namespace std;

class QuickSort {
public:
  void sort(vector<int> &arr) {
    // choose pivot point at arr[right], the last element.
    int m = static_cast<int>(arr.size());
    quickSort(arr, 0, m - 1);
  }

  void quickSort(vector<int> &arr, int left, int right) {
    if (left >= right)
      return;
    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot);
    quickSort(arr, pivot + 1, right);
  }

  int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left;
    while (i <= pivot) {
      
    }
  }

  void print(vector<int> &arr) {
    for (int i : arr) {
      cout << i << " ";
    }
    cout << endl;
  }
};

int main() {
  vector<int> arr{50, 25, 76, 38, 19, 58, 29, 88, 44, 22, 11, 34};
  QuickSort qs = QuickSort();
  qs.sort(arr);
  qs.print(arr);
  return 0;
}
