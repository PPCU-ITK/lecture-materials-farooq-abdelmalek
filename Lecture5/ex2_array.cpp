#include <iostream> // Include the iostream library for input/output operations

int main() {
    int size = 0; // Declare and initialize an integer variable 'size' to 0
    std::cout << "Enter the size for the array: "; // Prompt the user to enter the desired array size
    std::cin >> size; // Read the user's input and store it in the 'size' variable

    // Safety check for positive size (added for robustness)
    if (size <= 0) {
        std::cerr << "Invalid size entered. Exiting." << std::endl;
        return 1; // Return a non-zero exit code to indicate an error
    }

    // TODO 1: Allocate an array of 'size' doubles on the heap.
    // Store the pointer in a variable named 'p_arr'.
    // Use 'new[]' to allocate the array dynamically on the heap.
    double* p_arr = new double[size]; 

    // TODO 2: Write a loop to fill the array with values.
    for (int i = 0; i < size; ++i) { // Start a loop from i=0 up to (but not including) 'size'
        p_arr[i] = i * 1.5; // Access the array element at index 'i' and assign it a calculated value
    }

    // TODO 3: Write a loop to print all values in the array,
    // separated by a space.
    std::cout << "Array values: "; // Print a label for the array values
    for (int i = 0; i < size; ++i) { // Start a loop from i=0 up to (but not including) 'size'
        std::cout << p_arr[i] << " "; // Print the value of the element at index 'i', followed by a space
    }
    std::cout << std::endl; // Print a newline character to finish the line


    // TODO 4: Deallocate the array memory using the correct 'delete[]' operator.
    delete[] p_arr; // Use 'delete[]' to correctly deallocate the entire block of memory allocated with 'new[]'

    // TODO 5: (Good Practice) Set the pointer to 'nullptr'.
    p_arr = nullptr; // Set the pointer to nullptr to prevent it from becoming a dangling pointer

    std::cout << "Exercise 2 complete." << std::endl; // Print a message indicating the end of the exercise
    return 0; // Return 0 to indicate successful program execution
}