#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include "print_time.h"


// Function to print the current time
void printCurrentTime(const std::string& format) {
    // Get current time
    time_t currentTime = time(nullptr);
    
    // Convert the current time to a struct tm
    struct tm* timeinfo = localtime(&currentTime);
    
    // Format and print the current time
    char buffer[80];
    strftime(buffer, 80, format.c_str(), timeinfo);
    std::cout << "Current Time: " << buffer << std::endl;
}

void notTested() {
    std::cout << "I'm not tested" << std::endl;
}
