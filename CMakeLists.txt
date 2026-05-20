cmake_minimum_required(VERSION 3.10)

option(USE_ZIG_CC "Build with zig cc / zig c++" OFF)

if(USE_ZIG_CC)
  find_program(ZIG_EXECUTABLE zig REQUIRED)

  # CMake needs the compiler choice before project() enables the languages.
  set(CMAKE_C_COMPILER "${ZIG_EXECUTABLE}" CACHE FILEPATH "C compiler" FORCE)
  set(CMAKE_C_COMPILER_ARG1 cc CACHE STRING "zig cc subcommand" FORCE)
  set(CMAKE_CXX_COMPILER "${ZIG_EXECUTABLE}" CACHE FILEPATH "C++ compiler" FORCE)
  set(CMAKE_CXX_COMPILER_ARG1 c++ CACHE STRING "zig c++ subcommand" FORCE)
endif()

project("cpp_snippets" LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_subdirectory(basic)
add_subdirectory(sorting)
add_subdirectory(algorithm)
add_subdirectory(os)
add_subdirectory(smart_pointer)
add_subdirectory(design-pattern)
#add_subdirectory(benchmark_tests)
add_subdirectory(cache_test)
