#include <iostream>

int main() {
    // Simple test case
    int result = 2 + 2;
    if (result == 4) {
        std::cout << "Test Passed!" << std::endl;
        return 0; // Success
    }
    else {
        std::cerr << "Test Failed!" << std::endl;
        return 1; // Failure
    }
}
