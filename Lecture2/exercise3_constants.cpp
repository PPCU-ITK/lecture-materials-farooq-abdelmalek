// LECTURE 2 - EXERCISE 3: THE 'const' GUARANTEE
//
// In Python, a variable in ALL_CAPS is just a *convention*
// for a constant. In C++, 'const' is a *rule* enforced
// by the compiler.
//
// TASK 1: Compile this file.
//   g++ exercise3_constants.cpp -o exercise3
//
//   ...and a third time, a COMPILE-TIME ERROR!
//   Read the error. It should say something about
//   "assignment of read-only variable 'PI'".
//
// TASK 2: Fix the code.
//   You can't change a 'const' variable. The only
//   way to fix this is to comment out or delete
//   the line that tries to change PI.
//
// TASK 3: Define your own constants.
//   - Define a 'const int' for 'MONTHS_IN_YEAR' and set it to 12.
//   - Define a 'const double' for 'SPEED_OF_LIGHT' and set it
//     to 299792458.0.
//
// TASK 4: Use your constants.
//   - Calculate the number of months in 5 years and print it.
//   - Print the speed of light.
//
// TASK 5: Re-compile and run.
//   g++ exercise3_constants.cpp -o exercise3
//   ./exercise3

#include <iostream>

int main() {
    std::cout << "--- Exercise 3: The 'const' Guarantee ---" << std::endl;

    const double PI = 3.14159;
    std::cout << "The value of PI is: " << PI << std::endl;

    // --- TASK 2: Fix this line ---
    //PI = 4.0; // Someone is trying to redefine math!
    // ---

    std::cout << "PI is now... " << PI << std::endl;

    // --- TASK 3: Define your constants here ---
    const int MONTHS_IN_YEAR = 12;
    const double SPEED_OF_LIGHT = 299792458.0;
    // --- TASK 4: Use your constants here ---
    int months = 5 * MONTHS_IN_YEAR;
    std::cout << "5 years is " << months << " months." << std::endl;
    
    std::cout << "---------------------------------------" << std::endl;
    return 0;
}