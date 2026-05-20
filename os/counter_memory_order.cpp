#include <atomic>
#include <thread>
#include <vector>
#include <iostream>

int main() {
  std::atomic<int> counter{0};
  constexpr int counts = 100;
  constexpr int numThreads = 4;
  std::vector<std::thread> threads;
  threads.reserve(numThreads);

  auto worker = [&]() {
    for (int i = 0; i < counts; ++i) {
      counter.fetch_add(1, std::memory_order_relaxed);
    }
  };

  for (int i = 0; i < numThreads; i++) {
    threads.emplace_back(worker);
  }

  for (auto& t : threads) {
    if (t.joinable()) {
      t.join();
    }
  }
  
  if (counter != counts * numThreads) {
    std::cout << "counter(" << counter << ") is not equal" << std::endl;
  } else {
    std::cout << "counter(" << counter << ") is qeual to expected" << std::endl;
  }
}
