#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

int main(int argc, char *argv[]) {
    // Get current time
    time_t currentTime = time(nullptr);
    
    // Convert the current time to a struct tm
    struct tm* timeinfo = localtime(&currentTime);
    
    // Default format
    std::string format = "%c";
    
    // Check if a format argument is provided
    if (argc > 1) {
        format = argv[1];
    }
    
    // Format and print the current time
    char buffer[80];
    strftime(buffer, 80, format.c_str(), timeinfo);
    std::cout << "Current Time: " << buffer << std::endl;
    
    return 0;
}
