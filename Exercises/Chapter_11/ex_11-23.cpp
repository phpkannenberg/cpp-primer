/*
 * Exercise 11.23: Rewrite the map that stored vectors of children's names with a key 
 * that is the family last name for the exercises in 11.2.1 to use a multimap.
 */
 
#include <map>
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::multimap<std::string, std::pair<std::string, int>> families;
    
    families.insert({"Kannenberg", {"Pedro", 1996}});
    families.insert({"Kannenberg", {"Victoria", 2001}});
    families.insert({"Goulart", {"Julia", 1998}});
    families.insert({"Kannenberg", {"Kiara", 2005}});
    families.insert({"Goulart", {"Eduardo", 2002}});
    
    for (const auto &family : families)
    {
        std::cout << family.first << " "
                  << family.second.first << " "
                  << family.second.second << "\n";
    }
    
    return 0;
}
