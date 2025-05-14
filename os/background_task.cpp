#include <iostream>
#include <thread>

class background_task {
public:
  void operator()() const { std::cout << "thread run" << std::endl; }
};

int main() {
  background_task t;
  std::thread backgroundTask(t);
  backgroundTask.join();
  return 0;
}
