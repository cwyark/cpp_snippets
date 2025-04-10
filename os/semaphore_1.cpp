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
  std::thread t1(worker, 1);
  std::thread t2(worker, 2);
  std::thread t3(worker, 3);
  std::thread t4(worker, 4);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  return 0;
}
