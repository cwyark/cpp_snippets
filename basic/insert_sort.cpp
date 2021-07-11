#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    vector<int> arr{50, 25, 76, 38, 19, 58, 29, 88, 44, 22, 11, 34};
    insertionSort(arr);
    for (auto & v : arr) {
        cout << v << " ";
    }
    cout << endl;
}