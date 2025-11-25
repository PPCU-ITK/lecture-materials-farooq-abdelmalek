#include <iostream>

/**
 * @brief Simulates creating a user profile by allocating
 * memory on the heap.
 * * THIS FUNCTION CONTAINS A MEMORY LEAK.
 */
void create_user_profile() {
    // Allocate 4KB of memory for a "profile"
    // (This is 1000 * 4 bytes/int = 4000 bytes)
    int* profile_data = new int[1000];

    // Use the data
    profile_data[0] = 123;
    
    std::cout << "Created profile at address: " << profile_data << std::endl;
    
    // PROBLEM: We never call delete[] on profile_data.
    // The memory is leaked when this function returns.

    // TASK: Fix this leak. Add the correct 'delete[]' call.
}

int main() {
    std::cout << "Running memory leak simulation..." << std::endl;
    std::cout << "Press Ctrl+C to stop." << std::endl;
    std::cout << "Observe this program's memory usage in Task Manager or 'top'." << std::endl;

    // This loop will run forever, leaking memory on each iteration.
    for (long i = 1; ; ++i) {
        create_user_profile();
        if (i % 1000 == 0) {
            std::cout << "Leaked " << i << " profiles..." << std::endl;
        }
    }

    return 0;
}