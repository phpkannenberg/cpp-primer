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
 * 
 * Exercise 13.30: Write and test a swap function for your valuelike version of HasPtr.
 * Give your swap a print statement that notes when it is executed.
 *
 * Exercise 13.31: Give your class a < operator and define a vector of HasPtrs. Give
 * that vector some elements and then sort the vector. Note when swap is called.
 */
 
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class HasPtr
{
friend void swap(HasPtr&, HasPtr&);
public:
    // constructor
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    
    // copy constructor
    HasPtr(const HasPtr& hp): 
        ps(new std::string(*(hp.ps))), i(hp.i) { }
    
    // copy-assignment operator
    HasPtr& operator=(HasPtr hp)
    { 
        swap(*this, hp); 
        return *this;
    }

    
    // destructor
    ~HasPtr() { delete ps; }
    
    // less than operator
    bool operator<(const HasPtr& rhs) const { return *ps < *rhs.ps; }
    
    std::string *ps;
    int i;
};

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
    std::cout << "swapping " << *lhs.ps << " and " << *rhs.ps << '\n';
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main()
{
    std::vector<HasPtr> v;
    
    v.emplace_back("pedro");
    v.emplace_back("julia");
    v.emplace_back("popo");
    v.emplace_back("jessica");
    v.emplace_back("raica");
    v.emplace_back("augusto");
    v.emplace_back("xhop");
    
    std::sort(v.begin(), v.end());
    
    std::cout << "\nsorted vector:\n";
    for (const auto& hp : v)
        std::cout << *hp.ps << " ";
    std::cout << std::endl;
    
    return 0;
}
