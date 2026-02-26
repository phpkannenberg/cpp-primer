/*
 * Exercise 9.46: Rewrite the previous exercise using a position and length to manage
 * the strings. This time use only the insert function.
 */
 
#include <string>
#include <iostream>

std::string add_prefix_and_suffix(const std::string& name,
                                  const std::string& prefix,
                                  const std::string& suffix)
{
    std::string n{name};
    
    // inserts prefix
    n.insert(0, prefix + " ");
    
    // inserts suffix
    n.insert(n.size(), " " + suffix);
    
    return n;
}

int main()
{
    std::cout << add_prefix_and_suffix("Pedro", "Mr.", "Jr.") << "\n";
    return 0;
}
