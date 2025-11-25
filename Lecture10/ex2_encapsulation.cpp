#include <iostream>

class Thermometer {
private:
    double m_celsius;

public:
    // Constructor
    Thermometer(double initial_temp) {
        set_temperature(initial_temp);
    }

    // TODO: Implement set_temperature
    // Rule: If temp < -273.15, print an error and DO NOT update m_celsius.
    void set_temperature(double c) {
        // Logic goes here
    }

    // TODO: Implement get_celsius (Simple getter)
    double get_celsius() {
        return 0.0; // Placeholder
    }

    // TODO: Implement get_fahrenheit
    // Formula: (Celsius * 9.0/5.0) + 32
    double get_fahrenheit() {
        return 0.0; // Placeholder
    }
};

int main() {
    Thermometer t(25.0);
    std::cout << "Current F: " << t.get_fahrenheit() << std::endl;

    std::cout << "Trying to set to -300..." << std::endl;
    t.set_temperature(-300.0); // Should fail
    
    std::cout << "Current C: " << t.get_celsius() << std::endl; // Should still be 25.0

    return 0;
}