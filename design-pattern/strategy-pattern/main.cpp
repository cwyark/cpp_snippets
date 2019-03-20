#include <iostream>

class SortBehavior {
  public:
  virtual void sorting() = 0;
};

class QuickSort : public SortBehavior {
  public:
  virtual void sorting()
  {
    std::cout << "Quick Sorting" << std::endl;
  };
};

class MergeSort : public SortBehavior {
  public:
  virtual void sorting()
  {
    std::cout << "Merge Sort" << std::endl;
  }
};

class HeapSort : public SortBehavior {
  public:
  virtual void sorting()
  {
    std::cout << "Heap Sort" << std::endl;
  }
};

class Algothrim {
  SortBehavior* algo;

  public:
  Algothrim(){};
  void setAlgo(SortBehavior* algo)
  {
    this->algo = algo;
  }
  void sort()
  {
    if (this->algo != nullptr) {
      this->algo->sorting();
    }
  }
};

int main(int, char**)
{
  QuickSort quick;
  MergeSort merge;
  HeapSort heap;
  Algothrim algo;
  algo.setAlgo(&merge);
  algo.sort();
  algo.setAlgo(&quick);
  algo.sort();
  algo.setAlgo(&heap);
  algo.sort();
  return 0;
}
