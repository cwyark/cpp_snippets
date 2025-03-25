cmake_minimum_required(VERSION 3.10)

# Dynamically get all cpp files in the current directory
file(GLOB BASIC_CPP_FILES "*.cpp")

# For each cpp file, extract the filename (without extension) and create an executable target
foreach(cpp_file ${BASIC_CPP_FILES})
  get_filename_component(target_name ${cpp_file} NAME_WE)
  add_executable(${target_name} ${cpp_file})
endforeach()
