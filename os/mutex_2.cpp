#include <list>
#include <mutex>

using namespace std;

list<int> my_list;
mutex mtx;

void add_to_list(int value) {
  lock_guard<mutex> lock(mtx);
  my_list.push_back(value);
}

bool list_contains(int value) {
  lock_guard<mutex> lock(mtx);
  return find(my_list.begin(), my_list.end(), value) != my_list.end();
}

int main() {}
