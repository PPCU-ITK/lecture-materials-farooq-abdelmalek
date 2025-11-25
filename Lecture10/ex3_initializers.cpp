#include <iostream>
#include <string>

class Planet {
private:
    std::string m_name;
    // CONSTANT variable: Cannot be assigned to, must be initialized!
    const double m_gravity; 

public:
    // TODO: Fix this constructor!
    // Currently, this will cause a compiler error because you cannot 
    // assign to a const variable inside the body.
    // Use a Member Initializer List ( : m_gravity(g) ) instead.
    Planet(std::string name, double g) {
        m_name = name;
        // m_gravity = g; // DELETE THIS LINE and use initializer list
    }

    void print_info() {
        std::cout << "Planet: " << m_name << ", Gravity: " << m_gravity << " m/s^2" << std::endl;
    }
};

int main() {
    // Planet earth("Earth", 9.81);
    // earth.print_info();
    
    // Planet mars("Mars", 3.72);
    // mars.print_info();

    return 0;
}