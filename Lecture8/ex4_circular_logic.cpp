#include <iostream>
#include <memory>
#include <vector>

struct Worker; // Forward declaration

struct Manager {
    std::vector<std::shared_ptr<Worker>> workers;
    
    ~Manager() { std::cout << "Manager Destroyed\n"; }
    
    void add_worker(std::shared_ptr<Worker> w);
};

struct Worker {
    // TODO: This shared_ptr causes a cycle. Change it to std::weak_ptr<Manager>.
    std::shared_ptr<Manager> boss; 
    
    ~Worker() { std::cout << "Worker Destroyed\n"; }
};

void Manager::add_worker(std::shared_ptr<Worker> w) {
    workers.push_back(w);
}

int main() {
    {
        std::cout << "Creating Manager and Worker...\n";
        auto boss = std::make_shared<Manager>();
        auto employee = std::make_shared<Worker>();

        // Create the cycle
        boss->add_worker(employee);
        employee->boss = boss;

        std::cout << "Boss Ref Count: " << boss.use_count() << "\n";
        std::cout << "Worker Ref Count: " << employee.use_count() << "\n";
        
        std::cout << "Leaving scope...\n";
    }
    
    // If correct, you should see "Manager Destroyed" and "Worker Destroyed" below.
    // If incorrect, you will see nothing (Memory Leak).
    std::cout << "End of main.\n";
    return 0;
}