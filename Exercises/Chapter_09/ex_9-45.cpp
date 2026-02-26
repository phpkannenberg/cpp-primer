/*
 * Exercise 9.45: Write a function that takes a string representing a name and two other
 * strings representing a prefix, such as "Mr." or "Ms." and a suffix, such as "Jr." or
 * "III". Using iterators and the insert and append functions, generate and return a
 * new string with the suffix and prefix added to the given name.
 */
 
#include <string>
#include <iostream>

std::string add_prefix_and_suffix(const std::string& name,
                                  const std::string& prefix,
                                  const std::string& suffix)
{
    std::string n{name};
    
    // inserts prefix
    n.insert(n.begin(), prefix.begin(), prefix.end());
    n.insert(n.begin() + prefix.size(), ' ');
    
    // appends suffix
    n.append(" " + suffix);
    
    return n;
}

int main()
{
    std::cout << add_prefix_and_suffix("Pedro", "Mr.", "Jr.") << "\n";
    return 0;
}
