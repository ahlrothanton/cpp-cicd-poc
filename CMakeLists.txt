cmake_minimum_required(VERSION 3.5)
project(PrintTime)

# TODO: split CMakeLists.txt

### application
add_executable(print_time
    src/print_time.cpp
    src/main.cpp
)
target_link_libraries(print_time)

# Set compiler flags for different build types
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

### gtests - https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# TODO: conditionally include test files
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(print_time_test
    src/print_time.cpp
    tests/print_time_test.cpp
)
target_link_libraries(
    print_time_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(print_time_test)

### coverage lcov/gcov
# TODO: conditionally include coverage files
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(coverage)
append_coverage_compiler_flags()
