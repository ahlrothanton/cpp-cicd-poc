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

    // regex pattern for default format
    std::string ts = output.substr(prefix.size());
    std::regex pattern(R"(([A-Za-z]{3} [A-Za-z]{3} \d{2} \d{2}:\d{2}:\d{2} \d{4})\n)");
    ASSERT_TRUE(std::regex_match(ts, pattern)) << "Input does not match the pattern: " << ts;

}

// test print time with custom format
TEST(PrintTimeTest, CustomFormat) {
    testing::internal::CaptureStdout();
    printCurrentTime("%s");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find(prefix) == 0);
    std::cout << output << std::endl;

    // regex pattern for Unix timestamp
    std::string ts = output.substr(prefix.size());
    std::regex pattern("^\\s*\\d+\\s*$");
    ASSERT_TRUE(std::regex_match(ts, pattern)) << "Input does not match the pattern: " << ts;
}
