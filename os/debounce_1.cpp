/**
 * Implement a debounce function
 */

#include <chrono>
#include <iostream>
#include <thread>

bool read_state() {
  static bool toggle = true;
  toggle = !toggle;
  return toggle;
}

bool debounce(int ms) {
  static int last_stable_state = false;
  static auto last_change_time = std::chrono::steady_clock::now();
  bool current_state = read_state();
  if (current_state != last_stable_state) {
    last_change_time = std::chrono::steady_clock::now();
  }

  if (std::chrono::steady_clock::now() - last_change_time >
      std::chrono::milliseconds(ms)) {
    if (current_state != last_stable_state) {
      last_stable_state = current_state;
      return current_state;
    }
  }
  return false;
}

int main() {
  while (true) {
    if (debounce(100)) {
      std::cout << "Button pressed!\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
