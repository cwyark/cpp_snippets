/**
 * In an embedded system that manages a shared configuration file, you are
 * required to implement a semaphore mechanism that allows multiple devices to
 * read the configuration file simultaneously, but ensures exclusive access when
 * a device writes new configurations to the file. Consider the constraints of
 * maintaining minimal latency in read operations while ensuring consistency
 * during write operations.
 *
 */

#include <fstream>
#include <iostream>
#include <mutex>
#include <semaphore>
#include <thread>
#include <vector>

std::counting_semaphore<> maxAllowReaderSema(10);
std::binary_semaphore rw_sema(1);
std::mutex file_mutex;

void read_configuration(std::fstream &file) {
  while (true) {
    maxAllowReaderSema.acquire();
    rw_sema.acquire(); // ensure no writers is writing.
    std::cout << "get config\n";
    rw_sema.release();
    maxAllowReaderSema.release();
  }
}

void write_configuration(std::fstream &file) {
  while (true) {
    rw_sema.acquire();
    file << "configuration\n";
    rw_sema.release();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main() {
  std::fstream file("/tmp/config.txt",
                    std::ios::in | std::ios::out | std::ios::app);
  if (!file) {
    std::cout << "init file failed\n";
  }

  std::vector<std::thread> threads;
  for (int i = 0; i < 10; ++i) {
    threads.emplace_back(read_configuration, std::ref(file));
  }

  threads.emplace_back(write_configuration, std::ref(file));

  for (auto &th : threads)
    th.join();

  file.close();
}
