#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr) {
  for (size_t i = 1; i < arr.size(); ++i) {
    int key = arr[i];
    size_t j = i;
    // Use a single condition in the while loop to improve readability
    while (j > 0 && arr[j - 1] > key) {
      arr[j] = arr[j - 1];
      --j;
    }
    arr[j] = key;
  }
}

int main() {
  vector<int> arr{50, 25, 76, 38, 19, 58, 29, 88, 44, 22, 11, 34};
  insertionSort(arr);
  for (const auto &v : arr) {
    cout << v << " ";
  }
  cout << endl;
}
