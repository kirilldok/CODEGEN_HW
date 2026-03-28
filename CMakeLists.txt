cmake_minimum_required(VERSION 3.10)
project(CodegenTask)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(codegen_main src/main.cpp src/reg_alloc.cpp src/scheduler.cpp)
add_executable(codegen_test test/test_main.cpp src/reg_alloc.cpp src/scheduler.cpp)
