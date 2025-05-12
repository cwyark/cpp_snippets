#include <iostream>
#include <semaphore>
#include <thread>

std::counting_semaphore sema(3);

void worker(int id) {
  sema.acquire();
  std::cout << "Task " << id << " is running\n";
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "Task " << id << " is done\n";
  sema.release();
}

int main() {
  std::vector<std::thread> threads;
  for (int i = 0; i < 5; ++i) {
    threads.emplace_back(worker, i);
  }
  for (auto &t : threads) {
    t.join();
  }
  return 0;
}
