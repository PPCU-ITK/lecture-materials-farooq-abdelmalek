#include <iostream>

int main() {
    int power_level = 9000;
    
    // PART 1: The Crash
    // This pointer is NOT initialized. It points to a random memory location.
    // OR it might be nullptr (0x0), which is also invalid to write to.
    int* ptr = nullptr; 

    // UNCOMMENT the lines below to see the crash, then FIX IT.
    
    /*
    std::cout << "Attempting to write to address: " << ptr << std::endl;
    *ptr = 9001; // <--- CRASH HAPPENS HERE (Segmentation Fault)
    */

    // TODO: Fix the crash by ensuring 'ptr' points to 'power_level' 
    // BEFORE we try to write to *ptr.
    
    
    std::cout << "If you see this message, you fixed the crash!" << std::endl;
    std::cout << "Power Level is now: " << power_level << std::endl;

    return 0;
}