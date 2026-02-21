/*
 * Exercise 8.10: Write a program to store each line from a file in a vector<string>.
 * Now use an istringstream to read each element from the vector a word at a time.
 */
 
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        std::cout << "Use: " << argv[0] << " filename" << std::endl; 
        return EXIT_FAILURE;
    }
    
    std::vector<std::string> v;
    
    // Stores each line from a file in a vector
    std::ifstream ifstrm(argv[1]);
    std::string line;
    while (getline(ifstrm, line))
    {
        v.push_back(line);
    }
    
    // Prints each element of the vector
    std::cout << "Elements from the vector:" << std::endl;
    for (const auto elem : v)
    {
        std::cout << elem << std::endl;
    }
    
    // Uses an istringstream to read each element from the vector a word at a time
    std::cout << "Words from each element:" << std::endl;
    for (const auto line : v) 
    {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) 
        {
            std::cout << word << std::endl;
        }
    }
    
    return EXIT_SUCCESS;
}
