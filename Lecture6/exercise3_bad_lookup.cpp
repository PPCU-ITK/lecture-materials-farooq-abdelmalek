#include <iostream>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
};

// Our "global" database of students
std::vector<Student> database = {
    {101, "Alice"},
    {102, "Bob"},
    {103, "Charlie"}
};

/**
 * @brief Finds a student in the database.
 * @return A pointer to the student if found, or nullptr if not.
 */
Student* find_student_by_id(int id) {
    for (Student& s : database) {
        if (s.id == id) {
            return &s; // Return address of the student in the vector
        }
    }
    return nullptr; // Not found
}

int main() {
    // 1. A search that works
    std::cout << "--- Searching for ID 102 (Bob) ---" << std::endl;
    Student* p_bob = find_student_by_id(102);
    if (p_bob != nullptr) {
        std::cout << "Found: " << p_bob->name << std::endl;
    }
    std::cout << "----------------------------------\n" << std::endl;


    // 2. A search that will crash
    std::cout << "--- Searching for ID 999 (Doesn't Exist) ---" << std::endl;
    
    Student* p_student = find_student_by_id(999);
    
    // TASK: This is the fix to prevent the crash.
    if (p_student != nullptr) { // Check if the pointer is NOT null
        std::cout << "Found: " << p_student->name << std::endl;
    } else {
        std::cout << "Error: Student not found (ID 999)." << std::endl;
    }
    
    
    std::cout << "----------------------------------\n" << std::endl;

    return 0;
}