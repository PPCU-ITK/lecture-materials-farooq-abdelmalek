#include <iostream>
#include <string>

// --- MOCK LEGACY API (Do not modify these functions) ---
void connect_to_server(const std::string& id) {
    std::cout << "[API] Opening connection to server: " << id << "...\n";
}

void disconnect_from_server(const std::string& id) {
    std::cout << "[API] Closing connection to server: " << id << ".\n";
}
// ------------------------------------------------------

// TODO: Implement the RAII Wrapper class 'ServerConnection'
class ServerConnection {
    std::string server_id;
public:
    // 1. Constructor should accept an ID and call connect_to_server
    
    // 2. Destructor should call disconnect_from_server
};

void business_logic() {
    std::cout << "Doing some work inside business_logic...\n";
    
    // TODO: Instantiate your ServerConnection class here.
    // Example: ServerConnection conn("DB_Main");
    
    // When this function returns, the destructor should trigger automatically.
}

int main() {
    std::cout << "Starting program...\n";
    business_logic();
    std::cout << "Back in main. Connection should be closed by now.\n";
    return 0;
}