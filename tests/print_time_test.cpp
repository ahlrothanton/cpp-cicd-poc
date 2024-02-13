#include "../src/print_time.h"
#include <gtest/gtest.h>
#include <string>
#include <iomanip>
#include <iostream>

const std::string format = "%c";

TEST(PrintTimeTest, DefaultFormat) {
    printCurrentTime(format);
    std::cout << "Implement me!" << std::endl;
}

TEST(PrintTimeTest, CustomFormat) {
    printCurrentTime(format);
    std::cout << "Implement me!" << std::endl;
}
