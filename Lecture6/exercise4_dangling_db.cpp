#include <iostream>
#include <string>
#include <vector>

struct Student {
    int id;
    std::string name;
};

/**
 * @brief Sets up the student database by creating a local vector
 * and returning it by value (safe).
 */
std::vector<Student> setup_database() {
    // 'student_db' is now a LOCAL std::vector.
    // std::vector handles its own memory (on the heap) internally.
    std::vector<Student> student_db = {
        {201, "David"},
        {202, "Eve"}
    };
    std::cout << "Inside setup_database():" << std::endl;
    // We can't easily print the internal address, but the vector is valid.

    // The entire vector is returned. C++ efficiently handles this copy/move.
    return student_db;

} // 'student_db' is destroyed here, but its data is MOVED/COPIED to the caller.

int main() {
    std::cout << "Calling setup_database()..." << std::endl;
    
    // The vector is returned by value and stored in 'db_handle'.
    std::vector<Student> db_handle = setup_database();
    
    std::cout << "\nIn main():" << std::endl;

    // We no longer use a pointer; we access the vector safely.
    std::cout << "Accessing student data... " << std::endl;
    
    // Access the first student's name from the valid, copied vector.
    if (!db_handle.empty()) {
        std::cout << "Found student: " << db_handle[0].name << std::endl; 
    } else {
        std::cout << "Database is empty." << std::endl;
    }
    
    std::cout << "----------------------------------\n" << std::endl;

    return 0;
}