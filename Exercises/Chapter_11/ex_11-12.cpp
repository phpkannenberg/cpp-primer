/*
 * Exercise 11.12: Write a program to read a sequence of strings and ints, storing each 
 * into a pair. Store the pairs in a vector.
 */
 
#include <utility>
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::vector<std::pair<std::string, int>> pairs;
    
    std::string s;
    int n;
    while (std::cin >> s >> n)
        pairs.push_back(std::make_pair(s, n));
    
    std::cout << "\n";
    for (const auto &p : pairs)
        std::cout << p.first << " " << p.second << "\n";
    
    return 0;
}
