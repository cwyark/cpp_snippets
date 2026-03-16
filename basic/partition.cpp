#include <iostream>
#include <vector>

using namespace std;

void fPartition(vector<int> &arr) {
  int m = static_cast<int>(arr.size());
  int i = 0;
  // use the last element as the pivot.
  int pivot = arr[m - 1];
  for (int j = 0; j < m; ++j) {
    if (arr[j] <= pivot) {
      swap(arr[i], arr[j]);
      ++i;
    }
  }
}

int main() { 
  vector<int> arr{50, 25, 76, 38, 19, 58, 29, 88, 44, 22, 11, 34}; 
  fPartition(arr);
  for (int i : arr) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
