cmake_minimum_required(VERSION 3.10)
project("cpp_snippets")

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
