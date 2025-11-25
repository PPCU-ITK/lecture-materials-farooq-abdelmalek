#include <iostream>
#include <vector>
#include <string>
#include <set> // Required for std::set

void process_guest_list(const std::vector<std::string>& raw_list) {
    std::cout << "Raw list size: " << raw_list.size() << std::endl;

    // TODO: 1. Declare a std::set<std::string>
    
    // TODO: 2. Insert all elements from raw_list into the set
    //          Hint: You can loop and insert, or use the set constructor:
    //          std::set<std::string> unique_guests(raw_list.begin(), raw_list.end());

    // TODO: 3. Print the size of the set (should be smaller than raw list)

    std::cout << "--- Final Guest List (Sorted & Unique) ---" << std::endl;
    
    // TODO: 4. Print names from the set
}

int main() {
    std::vector<std::string> signups = {
        "Alice", "Bob", "Charlie", "Alice", 
        "David", "Bob", "Eve", "Alice"
    };

    process_guest_list(signups);

    return 0;
}