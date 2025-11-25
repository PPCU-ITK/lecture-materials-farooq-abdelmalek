#include <iostream>
#include <stdexcept> // Required for std::exception

// EXERCISE 5: Error Handling

// TODO: Modify this function to check if b is 0.
// If b is 0, throw std::runtime_error("Division by zero!");
double safe_divide(double a, double b) {
    return a / b;
}

int main() {
    double v1 = 10.0;
    double v2 = 0.0;
    double v3 = 5.0;

    // TODO: Wrap the following logic in a try-catch block.
    // Catch (const std::exception& e) and print e.what().
    
    std::cout << "Result 1: " << safe_divide(v1, v3) << "\n"; // 10 / 5
    std::cout << "Result 2: " << safe_divide(v1, v2) << "\n"; // 10 / 0 -> Should Throw!
    
    std::cout << "Program finished gracefully.\n";

    return 0;
}