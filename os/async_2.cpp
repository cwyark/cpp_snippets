#include <chrono>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

// Reference:
// https://eli.thegreenplace.net/2016/the-promises-and-challenges-of-stdasync-task-based-parallelism-in-c11/#id4

using namespace std;

int accumulate_block_worker_ret(int *data, size_t count) {
  this_thread::sleep_for(chrono::seconds(3));
  return accumulate(data, data + count, 0);
}

int main() {
  auto cpu_nums = thread::hardware_concurrency();
  cout << "cpu numbers: " << cpu_nums << endl;
  vector<int> v{1, 2, 3, 4, 5, 6};
  future<int> fut =
      async(launch::async, accumulate_block_worker_ret, v.data(), v.size());
  while (fut.wait_for(chrono::seconds(1)) != future_status::ready) {
    cout << "... not ready" << endl;
  }
  cout << "use_workder_in_std_async computed: " << fut.get() << endl;
}
