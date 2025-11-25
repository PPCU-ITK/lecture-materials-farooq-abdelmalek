#include <iostream>

// TODO: This function won't work. Why?
// (It's pass-by-value)
void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    std::cout << "[In swap_by_value] a=" << a << ", b=" << b << std::endl;
}

// TODO: Implement this function using pass-by-reference
// to make it correctly swap the values of 'a' and 'b'
// in the 'main' function.
void swap_by_reference(int& a, int& b) {
    // Your code here
}

int main() {
    int a = 10;
    int b = 20;

    std::cout << "--- Initial Values ---" << std::endl;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    std::cout << "\n--- Calling swap_by_value ---" << std::endl;
    swap_by_value(a, b);
    std::cout << "--- After swap_by_value ---" << std::endl;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    std::cout << "\n--- Calling swap_by_reference ---" << std::endl;
    // TODO: Call swap_by_reference
    // swap_by_reference(a, b);
    std::cout << "--- After swap_by_reference ---" << std::endl;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    return 0;
}