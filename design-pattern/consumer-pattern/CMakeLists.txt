cmake_minimum_required(VERSION 3.5)

add_executable(consumer-pattern main.cpp)

# Enable testing for the project
enable_testing()

# Add your test executable
add_executable(
  unit_tests # Name of your test executable
  test/test_main.cpp # Path to your test source file
  # Add other test source files here
)

# Link GoogleTest to your test executable
target_link_libraries(
  unit_tests
  gtest_main # GoogleTest entry point
)

# Add the tests to CTest's test list so they will be run with `make test` or `ctest`
include(GoogleTest)
gtest_discover_tests(unit_tests)