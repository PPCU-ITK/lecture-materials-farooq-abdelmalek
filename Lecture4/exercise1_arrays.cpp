#include <iostream>

int main() {
    // 1. Initialize an array of integers.
    int data[] = {10, 20, 30, 40, 50, 60};

    // 2. Calculate the number of elements in the array.
    //    Hint: Use sizeof(array) / sizeof(element_type)
    int n = sizeof(data) / sizeof(data[0]);
    std::cout << "Array has " << n << " elements." << std::endl;

    std::cout << "--- Printing with [ ] operator ---" << std::endl;

    // 3. Write a standard for-loop to iterate through the array.
    //    The loop should go from i = 0 up to (but not including) n.
    //
    // 4. Inside the loop, print the element at the current index
    //    using the [ ] operator (e.g., data[i]).

    // TODO: Write your for-loop here.
    for (int i = 0; i < n; ++i) {
        std::cout << data[i] << " ";
    }


    std::cout << std::endl;

    return 0;
}