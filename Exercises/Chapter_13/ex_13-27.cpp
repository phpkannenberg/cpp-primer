/*
 * Exercise 13.27: Define your own reference-counted version of HasPtr.
 */

#include <string>

class HasPtr
{
public:
    // constructor
    HasPtr(const std::string& s = std::string()):
        ps(new std::string(s)), i(0), ref_count(new int(1)) { }
    
    // copy constructor
    HasPtr(const HasPtr& hp):
        ps(hp.ps), i(hp.i), ref_count(hp.ref_count)
        { ++(*ref_count); }
    
    // copy-assignment constructor
    HasPtr& operator=(const HasPtr& hp)
    {
        ++(*hp.ref_count);
        
        if (--(*ref_count) == 0)
        {
            delete ps;
            delete ref_count;
        }
        
        ps = hp.ps;
        i = hp.i;
        ref_count = hp.ref_count;
        
        return *this;
    }
    
    // destructor
    ~HasPtr()
    {
        if (--(*ref_count) == 0) 
        {
            delete ps;
            delete ref_count;
        }
    }
    
    const std::string ps() { return *ps; }
    const int& i() { return i; }
    const int& ref_count() { return *ref_count; }

private:
    std::string *ps;
    int i;
    int *ref_count;
};
