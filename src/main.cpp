#include <iostream>
#include <string>
#include "print_time.h"


int main(int argc, char *argv[]) {
    // Default format
    std::string format = "%c";
    
    // Check if a format argument is provided
    if (argc > 1) {
        format = argv[1];
    }
    
    // Call the function to print the current time
    printCurrentTime(format);
    
    return 0;
}
