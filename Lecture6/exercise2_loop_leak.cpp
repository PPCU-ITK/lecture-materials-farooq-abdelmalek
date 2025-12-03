#include <iostream>

/**
 * @brief Simulates creating a user profile by allocating
 * memory on the heap.
 * * This function is now fixed and DOES NOT contain a memory leak.
 */
void create_user_profile() {
    // Allocate 4KB of memory for a "profile"
    // (This is 1000 * 4 bytes/int = 4000 bytes)
    int* profile_data = new int[1000]; // Allocation on the heap

    // Use the data
    profile_data[0] = 123;
    
    std::cout << "Created profile at address: " << profile_data << std::endl;
    
    // PROBLEM: We never call delete[] on profile_data.
    // The memory is leaked when this function returns.

    // TASK: Fix this leak. Add the correct 'delete[]' call.
    delete[] profile_data; // FIX: Deallocate the array memory from the heap.
    
    // Optional: Set pointer to nullptr after deletion
    // profile_data = nullptr; 
}

int main() {
    std::cout << "Running memory leak simulation (FIXED)..." << std::endl;
    std::cout << "The program's memory usage should now remain stable." << std::endl;
    std::cout << "Press Ctrl+C to stop." << std::endl;

    // This loop will run forever, but the memory is freed on each iteration.
    for (long i = 1; ; ++i) {
        create_user_profile();
        if (i % 1000 == 0) {
            // Note: The output is less useful now, as no memory is actually leaking.
            std::cout << "Processed " << i << " profiles without leaking." << std::endl;
        }
    }

    return 0;
}