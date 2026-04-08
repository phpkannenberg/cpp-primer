/*
 * Exercise 13.18: Define an Employee class that contains an employee name and a 
 * unique employee identifier. Give the class a default constructor and a constructor that 
 * takes a string representing the employee's name. Each constructor should generate
 * a unique ID by incrementing a static data member.
 *
 * Exercise 13.19: Implement whatever copy-control members you think Employee needs.
 */
 
#include <string>
#include <iostream>

class Employee
{
    friend int main();  // testing purposes
public:
    Employee() : name(), id(id_tracker++) { }
    Employee(const std::string& n) : name(n), id(id_tracker++) { }

    // copy constructor: copies name, generates new ID
    Employee(const Employee& e) : name(e.name), id(id_tracker++) { }

    // copy assignment: copies name, keeps original ID
    Employee& operator=(const Employee& e)
    {
        if (this != &e)
        {
            name = e.name;
        }
        return *this;
    }

private:
    std::string name;
    unsigned int id;
    static unsigned int id_tracker;
};

unsigned int Employee::id_tracker = 0;

int main()
{
    Employee e1;
    Employee e2("Marcos");
    Employee e3("Maria");
    Employee e4(e3);
    Employee e5 = e4;

    std::cout << "\nName: " << e1.name << " ID: " << e1.id;
    std::cout << "\nName: " << e2.name << " ID: " << e2.id;
    std::cout << "\nName: " << e3.name << " ID: " << e3.id;
    std::cout << "\nName: " << e4.name << " ID: " << e4.id;
    std::cout << "\nName: " << e5.name << " ID: " << e5.id;
    std::cout << std::endl;

    return 0;
}
