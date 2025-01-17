#include <iostream>

// Implement a hashtable.
// hashtable => should habe a hash function.
// A hashtable can be store in a array of linked list. And node of the linked
// list stores the original key and value.

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

template <typename K, typename T> class hashtable {
public:
  void insert(K key, T value) {}

  T get(K key) {}

  void delete(K key) {}

private:
  vector<ListNode> m_array;
};

int main() {}
