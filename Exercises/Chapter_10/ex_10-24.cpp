/*
 * Exercise 10.24: Use bind and check_size to find the first element in a vector of
 * ints that has a value greater than the length of a specified string value.
 */
 
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std::placeholders;

bool check_size(const std::string &s, std::string::size_type sz)
{
    return s.size() >= sz;
}

int main()
{
    std::vector<int> ints{0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                          10, 11, 12, 13, 14, 15, 16, 17};
    
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;
    
    auto first_greater = std::bind(check_size, word, _1);
    auto it = std::find_if(ints.begin(), ints.end(),
                           [&] (int a) -> bool { return !first_greater(a); });
    
    std::cout << "First element greater than the length of " << word
              << ": " << *it << ".\n";
    
    return 0;
}
