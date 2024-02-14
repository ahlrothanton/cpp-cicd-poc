#include "../src/print_time.h"
#include <gtest/gtest.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <regex>


std::string prefix = "Current Time: ";

// test print time with default format
TEST(PrintTimeTest, DefaultFormat) {
    testing::internal::CaptureStdout();
    printCurrentTime("%c");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find(prefix) == 0);
    std::cout << output << std::endl;
}

// test print time with custom format
TEST(PrintTimeTest, CustomFormat) {
    testing::internal::CaptureStdout();
    printCurrentTime("%u");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find(prefix) == 0);
    std::cout << output << std::endl;
}
