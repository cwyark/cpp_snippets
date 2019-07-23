cmake_minimum_required(VERSION 3.0)

add_executable(push_back push_back.cpp)
target_link_libraries(push_back
  benchmark)
target_compile_options(push_back
  PUBLIC
  -fno-omit-frame-pointer
  )
