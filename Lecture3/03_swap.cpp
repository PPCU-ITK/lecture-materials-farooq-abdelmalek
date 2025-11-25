#include <iostream>

// TODO 1: Write a function named 'swap_fruit'.
// It should take two int pointers as arguments (int* a, int* b).
// It should swap the values stored at those addresses.
// (You will need a temporary integer variable inside the function).

void swap_fruit(int* a, int* b) {
    // Your code here
}

int main() {
    int apple = 100;  // Represents Apple Count
    int orange = 5;   // Represents Orange Count

    std::cout << "Before Swap -> Apple: " << apple << ", Orange: " << orange << std::endl;

    // TODO 2: Call swap_fruit passing the addresses of apple and orange.
    

    std::cout << "After Swap  -> Apple: " << apple << ", Orange: " << orange << std::endl;

    // Check logic
    if (apple == 5 && orange == 100) {
        std::cout << "SUCCESS: Fruits swapped!" << std::endl;
    } else {
        std::cout << "FAILURE: Fruits did not swap." << std::endl;
    }

    return 0;
}