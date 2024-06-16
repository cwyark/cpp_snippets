#ifndef MAIN_H
#define MAIN_H

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

// Abstract class Light
class Light {
public:
  virtual ~Light() {}

  /**
   * abtract method to turn on the light.
   */
  virtual void turnOn() = 0;
  /**
   *  abstract method to turn off the light.
   */
  virtual void turnOff() = 0;
  /**
   * abstract method to get the brand name.
   */
  virtual std::string getBrandName() = 0;
  /**
   * abstract method to get the light id.
   */
  virtual int getId() = 0;
};

struct CommandMessage {
  std::string brand;
  int id;
  std::string action;
  CommandMessage(const std::string &br, int i, const std::string &act)
      : brand(br), id(i), action(act) {}
};

// Thread-safe message queue
class MessageQueue {
private:
  std::queue<CommandMessage> queue;
  mutable std::mutex mutex;
  std::condition_variable cond;

public:
  /**
   * push a new message into the queue
   */
  void push(const CommandMessage &message) {
    std::lock_guard<std::mutex> lock(mutex);
    queue.push(message);
    cond.notify_one();
  }

  /**
   * pop a message from the queue
   */
  CommandMessage pop() {
    std::unique_lock<std::mutex> lock(mutex);
    while (queue.empty()) {
      cond.wait(lock);
    }
    CommandMessage value = queue.front();
    queue.pop();
    return value;
  }
};

#endif // MAIN_H