// LECTURE 2 - EXERCISE 4: TYPE CONVERSIONS
//
// C++ will sometimes implicitly (automatically) convert types.
// This can be helpful (int -> double) or dangerous (double -> int).
//
// This program calculates a simple grade average.
//
// TASK 1: Compile and run this file.
//   g++ exercise4_truncation.cpp -o exercise4
//   ./exercise4
//
//   Observe the output. Notice anything... wrong?
//   The average of 80, 95, and 88 should be 87.666...
//   Why is the 'final_grade_int' variable 87?
//
//   This is called TRUNCATION. C++ throws away the decimal
//   part when converting a 'double' to an 'int'.
//
// TASK 2: Use static_cast.
//   Let's say we want to round to the *nearest* whole number,
//   not just truncate. A common C-style trick is to add 0.5
//   before converting to an integer.
//
//   - Create a new 'int' variable called 'rounded_grade'.
//   - Set it equal to 'precise_average + 0.5'.
//   - You will probably get a compiler *warning* about
//     data loss.
//
//   - Now, "fix" it by using a 'static_cast' to tell
//     the compiler you *intend* to do this.
//
//   int rounded_grade = static_cast<int>(precise_average + 0.5);
//
// TASK 3: Print 'rounded_grade' and verify it's 88.
//
// TASK 4: Re-compile and run.
//   g++ exercise4_truncation.cpp -o exercise4
//   ./exercise4

#include <iostream>

int main() {
    std::cout << "--- Exercise 4: Type Conversions ---" << std::endl;

    int grade1 = 80;
    int grade2 = 95;
    int grade3 = 88;

    // Implicit conversion: (grade1 + grade2 + grade3) is an 'int'.
    // 3.0 is a 'double'.
    // The 'int' is "promoted" to a 'double' for the division.
    double precise_average = (grade1 + grade2 + grade3) / 3.0;
    
    std::cout << "The precise average is: " << precise_average << std::endl;
    
    // Implicit conversion: 'precise_average' (a 'double') is
    // "truncated" to fit into an 'int' box.
    int final_grade_int = precise_average;

    std::cout << "The truncated integer grade is: " << final_grade_int << std::endl;

    // --- TASK 2: Use static_cast to round properly ---
    int rounded_grade = static_cast<int>(precise_average + 0.5);

    // int rounded_grade = ...
    
    // --- TASK 3: Print your rounded grade ---
    std::cout << "The rounded grade is: " << rounded_grade << std::endl;
    

    std::cout << "------------------------------------" << std::endl;
    return 0;
}