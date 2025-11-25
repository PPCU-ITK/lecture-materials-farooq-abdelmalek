#include <iostream>
#include <string>

class LoudObject {
private:
    std::string m_name;
    
public:
    LoudObject(std::string name) : m_name(name) {
        std::cout << "Born: " << m_name << std::endl;
    }
    
    // TODO: Implement the Destructor (~LoudObject)
    // It should print "Died: " followed by m_name
    
};

int main() {
    std::cout << "--- Start of Main ---" << std::endl;
    
    LoudObject a("Object A");
    
    {
        std::cout << "--- Entering Scope 1 ---" << std::endl;
        LoudObject b("Object B");
        
        if (true) {
             std::cout << "--- Entering Scope 2 ---" << std::endl;
             LoudObject c("Object C");
             std::cout << "--- Exiting Scope 2 ---" << std::endl;
        }
        
        std::cout << "--- Exiting Scope 1 ---" << std::endl;
    }
    
    std::cout << "--- End of Main ---" << std::endl;
    return 0;
}