/*
 * Exercise 11.14: Extend the map of children to their family name that you wrote for the
 * exercises in 11.2.1 by having the vector store a pair that holds a child's name and 
 * birthday.
 */
 
#include <map>
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::map<std::string, std::vector<std::pair<std::string, int>>> families;
    
    families["Kannenberg"] = {{"Pedro", 1996}, {"Victoria", 2001}};
    families["Goulart"] = {{"Julia", 1997}};
    
    families["Kannenberg"].push_back({"Kiara", 2005});
    families["Goulart"].push_back({"Eduardo", 2002});
    
    for (const auto &family : families)
    {
        std::cout << family.first << ":";
        for (const auto &child : family.second)
        {
            std::cout << " " << child.first << " " << child.second << ";";
        }
        std::cout << "\n";
    }
    
    return 0;
}
