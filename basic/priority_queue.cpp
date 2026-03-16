#include <iostream>

using namespace std;

int main() {
  cout << "max heap" << endl;
  priority_queue<int> pq;
  pq.push(10);
  pq.push(5);
  pq.push(20);
  cout << pq.top() << endl;
  pq.pop();
  cout << pq.top() << endl;
  cout << "min heap" << endl;
  priority_queue<int, vector<int>, greater<int>> mpq;
  mpq.push(10);
  mpq.push(5);
  mpq.push(20);
  cout << mpq.top() << endl;
  mpq.pop();
  cout << mpq.top() << endl;
  return 0;
}
