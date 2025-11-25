#include <iostream>
#include <string>

struct Student {
    std::string name;
    int score;
};

/**
 * @brief Prints a student's info to the console.
 */
void print_student(const Student& s) {
    std::cout << "  " << s.name << " | Score: " << s.score << std::endl;
}

/**
 * @brief Attempts to reset a student's score to 0.
 * THIS IS THE BROKEN FUNCTION.
 */
void reset_score_by_value(Student s) { // s is a COPY
    std::cout << "  Inside by_value: Resetting " << s.name << "'s score..." << std::endl;
    s.score = 0; // This only changes the COPY
    std::cout << "  Inside by_value: Score is now " << s.score << std::endl;
} // 's' (the copy) is destroyed here.

/**
 * TASK: Implement this function.
 * @brief Resets a student's score to 0 using a pointer.
 */
// void reset_score_by_pointer(Student* p_student) {
//     // HINT: Use the -> (arrow) operator to access
//     // members of a struct via a pointer.
//     std::cout << "  Inside by_pointer: Resetting " 
//               << ... << "'s score..." << std::endl;
//     ...
// }

int main() {
    Student student_a = {"Alice", 85};

    std::cout << "--- Testing pass-by-value ---" << std::endl;
    std::cout << "Before call:" << std::endl;
    print_student(student_a);
    
    reset_score_by_value(student_a);
    
    std::cout << "After call:" << std::endl;
    print_student(student_a); // Notice the score is still 85!
    std::cout << "-------------------------------\n" << std::endl;


    std::cout << "--- Testing pass-by-pointer ---" << std::endl;
    std::cout << "Before call:" << std::endl;
    print_student(student_a);

    // TASK: Call your 'reset_score_by_pointer' function here.
    // HINT: You must pass the *address* of student_a.
    // reset_score_by_pointer(...);
    
    std::cout << "After call:" << std::endl;
    print_student(student_a); // This should now show 0!
    std::cout << "-------------------------------\n" << std::endl;

    return 0;
}