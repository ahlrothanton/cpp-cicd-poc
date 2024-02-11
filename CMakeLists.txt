cmake_minimum_required(VERSION 3.5)
project(PrintTime)

# Application
add_executable(PrintTime src/print_time/main.cpp)
target_link_libraries(PrintTime)
