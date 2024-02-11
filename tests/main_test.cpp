#include <gtest/gtest.h>
#include "print_time.h" // Assuming you have a header file for your printCurrentTime function

// Test fixture class
class PrintTimeTest : public ::testing::Test {
protected:
    // No setup needed for this simple test case
    // No tear down needed for this simple test case
};

// Test case for printing the current time with default format
TEST_F(PrintTimeTest, DefaultFormat) {
    // Redirect cout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old_stdout = std::cout.rdbuf(buffer.rdbuf());

    // Call the function to print the current time
    printCurrentTime("%c");

    // Restore old cout
    std::cout.rdbuf(old_stdout);

    // Check if the output matches the expected format
    std::string output = buffer.str();
    // Replace newline character with an empty string
    output.erase(std::remove(output.begin(), output.end(), '\n'), output.end());
    ASSERT_EQ(output, "Current Time: " + std::string(buffer.str().c_str()) + " ");
}

// Test case for printing the current time with custom format
TEST_F(PrintTimeTest, CustomFormat) {
    // Redirect cout to a stringstream to capture output
    std::stringstream buffer;
    std::streambuf* old_stdout = std::cout.rdbuf(buffer.rdbuf());

    // Call the function to print the current time
    printCurrentTime("%Y-%m-%d %H:%M:%S");

    // Restore old cout
    std::cout.rdbuf(old_stdout);

    // Check if the output matches the expected format
    std::string output = buffer.str();
    // Replace newline character with an empty string
    output.erase(std::remove(output.begin(), output.end(), '\n'), output.end());
    ASSERT_EQ(output, "Current Time: " + std::string(buffer.str().c_str()) + " ");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
