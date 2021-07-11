#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                // swap them
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int main() {
    vector<int> arr{50, 25, 76, 38, 19, 58, 29, 88, 44, 22, 11, 34};
    selectionSort(arr);
    for (auto & v : arr) {
        cout << v << " ";
    }
    cout << endl;
    exit(EXIT_SUCCESS);
}