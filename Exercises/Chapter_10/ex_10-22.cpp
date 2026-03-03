/*
 * Exercise 10.22: Rewrite the program to count words of size 6 or less using functions
 * in place of the lambdas.
 */
 
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool check6(const std::string &s)
{
    return s.size() <= 6;
}

int main()
{
    std::vector<std::string> words;
    
    std::cout << "Enter some words: ";
    std::string word;
    while (std::cin >> word)
        words.push_back(word);
    
    std::cout << "\nThere were " << std::count_if(words.begin(), words.end(), check6)
              << " words of size 6 or less.\n";
    
    return 0;
}
