#include <iostream>
#include <vector>

class MaxHeap {
private:
  // 使用陣列作為二元完全樹
  std::vector<int> pData;
  void heapifyUp(int index) {
    while (index > 0) {
      int parent = (index - 1) / 2;
      if (pData[index] > pData[parent]) {
        std::swap(pData[index], pData[parent]);
        index = parent;
      } else {
        break;
      }
    }
  }
  void heapifyDown(int index) {
    int n = static_cast<int>(pData.size());
    while (true) {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      int largest = index;
      if (left < n && pData[left] > pData[largest]) {
        largest = left;
      }
      if (right < n && pData[right] > pData[largest]) {
        largest = right;
      }
      if (largest != index) {
        std::swap(pData[index], pData[largest]);
        index = largest;
      } else {
        break;
      }
    }
  }

public:
  bool empty() const { return pData.empty(); }

  int size() const { return pData.size(); }

  int top() const {
    if (empty()) {
      throw std::runtime_error("heap is empty");
    }
    return pData[0];
  }

  void push(int value) {
    pData.push_back(value);
    heapifyUp(static_cast<int>(pData.size()) - 1);
  }

  void pop() {
    if (empty()) {
      throw std::runtime_error("heap is empty");
    }
    pData[0] = pData.back();
    pData.pop_back();
    if (!empty()) {
      heapifyDown(0);
    }
  }
};

int main() {
  MaxHeap mp;
  mp.push(20);
  mp.push(10);
  mp.push(5);
  while (!mp.empty()) {
    std::cout << mp.top() << std::endl;
    mp.pop();
  }
  std::cout << std::endl;
  return 0;
}
