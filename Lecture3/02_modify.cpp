#include <iostream>

// TODO 1: Implement the 'tripler' function.
// It should take an integer POINTER as a parameter.
// It should multiply the value AT that address by 3.
void tripler(int* number_ptr) {
    // Your code here
    // Remember: *number_ptr gets you the value
}

int main() {
    int my_score = 10;

    std::cout << "Score before: " << my_score << std::endl;

    // TODO 2: Call the tripler function.
    // Hint: You cannot pass 'my_score' directly. You must pass its address!
    

    std::cout << "Score after (should be 30): " << my_score << std::endl;

    return 0;
}