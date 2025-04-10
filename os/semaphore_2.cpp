/**
 * In a real-time embedded system that processes sensor data, multiple sensor
 * nodes push data to a shared buffer. Implement a semaphore mechanism that
 * ensures data integrity when multiple nodes (sensors) simultaneously try to
 * write to the buffer. Design your solution considering the constraints of
 * embedded systems like limited processing power and memory footprint.
 * Additionally, ensure that no data is lost when the buffer reaches its
 * capacity.
 *
 */

#include <atomic>
#include <csignal>
#include <iostream>
#include <mutex>
#include <queue>
#include <semaphore>
#include <signal.h>
#include <thread>
#include <vector>

int buffer_len = 10;
std::queue<int> data_queue;
std::counting_semaphore<> fullSema(0);
std::counting_semaphore<> emptySema(buffer_len);
std::atomic<bool> should_stop = false;

std::mutex mtx;

void producer(int id) {
  while (!should_stop) {
    emptySema.acquire(); // wait for empty slot
    {
      std::lock_guard<std::mutex> lock(mtx);
      data_queue.push(1);
      std::cout << "Task " << id << " push data: 1\n";
    }

    fullSema.release();
  }
}

void consumer(int id) {
  while (!should_stop) {
    fullSema.acquire();
    int data;
    {
      std::lock_guard<std::mutex> lock(mtx);
      if (!data_queue.empty()) {
        data = data_queue.front();
        data_queue.pop();
      }
      std::cout << "Task " << id << " pop data: " << data << std::endl;
    }

    emptySema.release();
  }
}

void signal_handler(int sig) {
  if (sig == SIGINT) {
    should_stop = true;
  }
}

int main() {
  int threadCounts = 20;
  signal(SIGINT, signal_handler);
  std::vector<std::thread> producerThreads;
  for (int i = 0; i < threadCounts; ++i) {
    producerThreads.emplace_back(producer, i);
  }
  std::vector<std::thread> consumerThreads;
  for (int i = 0; i < threadCounts; ++i) {
    consumerThreads.emplace_back(consumer, i);
  }
  for (auto &th : producerThreads)
    th.join();
  for (auto &th : consumerThreads)
    th.join();
  return 0;
}
