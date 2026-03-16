#include <iostream>
#include <vector>

using namespace std;

class MergeSort {
public:
  void sort(vector<int> &arr) {
    if (arr.empty()) return;
    int m = static_cast<int>(arr.size());
    mergeSort(arr, 0, m - 1);
  }

  void merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> v(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
      if (arr[i] < arr[j]) {
        v[k++] = arr[i++];
      } else {
        v[k++] = arr[j++];
      }
    }
    while (i <= mid) {
      v[k++] = arr[i++];
    }
    while (j <= right) {
      v[k++] = arr[j++];
    }
    // copy the sorted back to &arr
    for (int p = 0; p < static_cast<int>(v.size()); ++p) {
      arr[left + p] = v[p];
    }
  }

  // merge interval: [left, mid] and [mid + 1, right]
  void mergeSort(vector<int> &arr, int left, int right) {
    // base case: if the range has 0 or 1 element, it is already sorted.
    if (left >= right)
      return;
    int mid = left + (right - left) / 2;
    // merge the left half sub array
    mergeSort(arr, left, mid);
    // merge the right half sub array
    mergeSort(arr, mid + 1, right);
    // merge the sorted halves.
    merge(arr, left, mid, right);
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
  MergeSort ms = MergeSort();
  ms.sort(arr);
  ms.print(arr);
  return 0;
}
