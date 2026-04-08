/*
 * Exercise 13.5: Given the following sketch of a class, write a copy constructor that 
 * copies all the members. Your constructor should dynamically allocate a new string
 * and copy the object to which ps points, rather than copying ps itself.
 *
 * Exercise 13.8: Write the assignment operator for the HasPtr class from exercise 13.5.
 * As with the copy constructor, your assignment operator should copy the object to
 * which ps points.
 *
 * Exercise 13.11: Add a destructor to your HasPtr class from the previous exercises.
 */
 
#include <string>

class HasPtr
{
public:
    // constructor
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    
    // copy constructor
    HasPtr(const HasPtr& hp): 
        ps(new std::string(*(hp.ps))), i(hp.i) { }
    
    // copy-assignment operator
    HasPtr& operator=(const HasPtr& hp)
    { 
        if (this != &hp)  // handles self-assignment
        {
            std::string* new_ps = new std::string(*(hp.ps));  // allocates new memory
            delete ps;  // frees old memory
            ps = new_ps;
            i = hp.i;
        }
        return *this;
    }
    
    // destructor
    ~HasPtr() { delete ps }
    
private:
    std::string *ps;
    int i;
};
