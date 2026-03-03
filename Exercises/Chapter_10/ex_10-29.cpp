/*
 * Exercise 10.29: Write a program using stream iterators to read a text file into a vector
 * of strings.
 */
 
#include <iterator>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Use: " << argv[0] << " filename" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::vector<std::string> v;
    std::ifstream ifstrm(argv[1]);
    std::istream_iterator<std::string> in(ifstrm), end;
    
    while (in != end)
    {
        v.push_back(*in);
        ++in;
    }
    
    std::for_each(v.begin(), v.end(), [] (std::string s) { std::cout << s << " "; });
    std::cout << std::endl;
    
    return EXIT_SUCCESS;
}
