// not a good practice.
#include "../main.hpp"
#include <gtest/gtest.h>

// Test fixture class for PhilipsLight
class PhilipsLightTest : public ::testing::Test {
protected:
  PhilipsLight philipsLight{"Philips", 1};

  PhilipsLightTest() {}

  ~PhilipsLightTest() override {}
};

// Test method turnOn
TEST_F(PhilipsLightTest, TurnsOn) { philipsLight.turnOn(); }

// Test method turnOff
TEST_F(PhilipsLightTest, TurnsOff) {
  philipsLight.turnOff();
  // Assertions to verify the state after turning off
}

// Repeat the process for OsramLight
class OsramLightTest : public ::testing::Test {
protected:
  OsramLight osramLight{"Osram", 1};

  OsramLightTest() {}

  ~OsramLightTest() override {}
};

// Test method turnOn
TEST_F(OsramLightTest, TurnsOn) { osramLight.turnOn(); }

// Test method turnOff
TEST_F(OsramLightTest, TurnsOff) { osramLight.turnOff(); }

// Testing the MessageQueue
TEST(MessageQueueTest, PushPop) {
  MessageQueue queue;
  CommandMessage cmd("TestBrand", 0, "ON");

  queue.push(cmd);

  CommandMessage receivedCmd = queue.pop();

  EXPECT_EQ(cmd.brand, receivedCmd.brand);
  EXPECT_EQ(cmd.id, receivedCmd.id);
  EXPECT_EQ(cmd.action, receivedCmd.action);
}

// The main function simply runs all the tests that have been declared with
// TEST()
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
