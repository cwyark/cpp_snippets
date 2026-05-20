#include <atomic>
#include <iostream>
#include <thread>

// create 2 threads, writer and reader. writer writes value to the variable data and reader reads the modified value.
int main() {
  int data{0};
  std::atomic<bool> ready{false};
  
  // create reader first.
  std::thread reader([&]() {
    while (!ready.load(std::memory_order_acquire)) {
      // wait.
    }
    std::cout << "data is " << data << std::endl;
  });
  

  // then create writer later.
  std::thread writer([&]() {
    data = 42;
    ready.store(true, std::memory_order_release);
  });

  writer.join();
  reader.join();

  std::cout << "spsc finished" << std::endl;

  return 0;
}
