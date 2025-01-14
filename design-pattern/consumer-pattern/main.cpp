#include "main.hpp"
#include <iostream>
#include <ostream>
#include <thread>

class PhilipsLight : public Light {
private:
  std::string _brandName;
  int _id;

public:
  PhilipsLight(const std::string &name, int id) : _brandName(name), _id(id) {}

  void turnOn() override {
    // philps_driver_function_A();
    std::cout << _brandName << " light is turned ON." << std::endl;
  }

  void turnOff() override {
    // philps_driver_function_B();
    std::cout << _brandName << " light is turned OFF." << std::endl;
  }

  std::string getBrandName() override { return _brandName; }

  int getId() override { return _id; }
};

class OsramLight : public Light {
private:
  std::string _brandName;
  int _id;

public:
  // Constructor with brand name
  OsramLight(const std::string &name, int id) : _brandName(name), _id(id) {}

  // Override Light's methods
  void turnOn() override {
    // osram_driver_function_A();
    std::cout << _brandName << " light is turned ON." << std::endl;
  }

  void turnOff() override {
    // osram_driver_function_B();
    std::cout << _brandName << " light is turned OFF." << std::endl;
  }

  std::string getBrandName() override { return _brandName; }

  int getId() override { return _id; }
};

// Producer class
class Producer {
private:
  MessageQueue &queue;

public:
  Producer(MessageQueue &q) : queue(q) {}

  void produce(CommandMessage &message) { queue.push(message); }
};

// Consumer class
class Consumer {
private:
  MessageQueue &queue;
  std::vector<std::shared_ptr<Light>> lights;

public:
  Consumer(MessageQueue &q, std::vector<std::shared_ptr<Light>> &ls)
      : queue(q), lights(ls) {}

  void consume() {
    while (true) {
      CommandMessage message = queue.pop();

      for (auto &light : lights) {
        if (light->getBrandName() == message.brand) {
          if (message.action == "ON") {
            light->turnOn();
          } else if (message.action == "OFF") {
            light->turnOff();
          }
          break;
        }
      }
    }
  }
};

int main() {
  // Create a message queue for communication
  MessageQueue messageQueue;

  // Create a vector of lights of different brands
  std::vector<std::shared_ptr<Light>> lights;

  lights.push_back(std::make_shared<PhilipsLight>("Philps", 0));
  lights.push_back(std::make_shared<PhilipsLight>("Philps", 1));
  lights.push_back(std::make_shared<OsramLight>("Orsam", 0));
  lights.push_back(std::make_shared<OsramLight>("Orsam", 1));

  // Create producer and consumer
  Producer producer(messageQueue);
  Consumer consumer(messageQueue, lights);

  // Start consumer thread
  std::thread consumerThread(&Consumer::consume, &consumer);

  // Produce messages
  auto message_1 = CommandMessage("Philps", 0, "ON");
  producer.produce(message_1);
  auto message_2 = CommandMessage("Orsam", 0, "ON");
  producer.produce(message_2);
  auto message_3 = CommandMessage("Orsam", 1, "ON");
  producer.produce(message_3);

  // Let's wait a bit to see the output
  std::this_thread::sleep_for(std::chrono::seconds(1));

  auto message_4 = CommandMessage("Philps", 0, "OFF");
  producer.produce(message_4);
  auto message_5 = CommandMessage("Orsam", 0, "OFF");
  producer.produce(message_5);
  auto message_6 = CommandMessage("Orsam", 1, "OFF");
  producer.produce(message_6);

  // Normally, we would have some condition to exit the consumer loop
  // For the purpose of this example, we'll just join the thread after a delay
  std::this_thread::sleep_for(std::chrono::seconds(1));
  consumerThread.join();

  // since we declare shared_ptr for our light objects, it will automatically
  // recycle.

  return 0;
}
