#include <iostream>
#include <queue>
#include <thread>

struct Command {
  std::string name;
};

// a thread-safe queue.
class MessageQueue {
public:
  void push(const Command &cmd) {
    {
      std::lock_guard<std::mutex> lock(mutex);
      if (closed)
        return;
      queue.push(std::move(cmd));
    }

    cond.notify_one();
  }

  std::optional<Command> pop() {
    std::unique_lock<std::mutex> lock(mutex);
    cond.wait(lock, [&] { return closed || !queue.empty(); });
    if (queue.empty()) {
      return std::nullopt;
    }
    Command cmd = std::move(queue.front());
    queue.pop();
    return cmd;
  }

  void close() {
    {
      std::lock_guard<std::mutex> lock(mutex);
      closed = true;
    }

    cond.notify_all();
  }

  bool isEmpty() {
    std::lock_guard<std::mutex> lock(mutex);
    return queue.empty();
  }

private:
  std::queue<Command> queue;
  std::condition_variable cond;
  mutable std::mutex mutex;
  bool closed{false};
};

int main() {
  MessageQueue mq;
  constexpr int kCount = 10;
  std::thread producer([&]() {
    for (int i = 0; i < kCount; ++i) {
      Command cmd(std::format("task-{}", i));
      std::cout << "pushing command: " << cmd.name << std::endl;
      mq.push(cmd);
    }
    mq.close();
  });

  std::thread consumer([&]() {
    while (true) {
      auto cmd = mq.pop();
      if (cmd.has_value()) {
        std::cout << cmd->name << std::endl;
      } else {
        break;
      }
    }
  });

  producer.join();
  consumer.join();
  return 0;
}
