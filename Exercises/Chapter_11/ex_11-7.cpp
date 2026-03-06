/*
 * Exercise 11.7: Define a map for which the key is the family's last name and the value
 * is a vector of the children's name. Write code to add new families and to add new 
 * children to an existing family.
 */
 
#include <map>
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::map<std::string, std::vector<std::string>> families;
    
    families["Kannenberg"] = {"Pedro", "Victoria"};
    families["Goulart"] = {"Julia"};
    
    families["Kannenberg"].push_back("Tonia");
    families["Goulart"].push_back("Eduardo");
    
    for (const auto &family : families)
    {
        std::cout << family.first << ":";
        for (const auto &child : family.second)
        {
            std::cout << " " << child << ";";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
