/*
 * Exercise 10.13: The library defines an algorithm named partition that takes a predicate
 * and partitions the container so that values for which the predicate is true appear
 * in the first part and those for which the predicate is false appear in the second part.
 * The algorithm returns an iterator just past the last element for which the predicate
 * returned true. Write a function that takes a string and returns a bool indicating
 * whether the string has five characters or more. Use that function to partition words.
 * Print the elements that have five or more characters.
 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

bool has_less_than_five_char(const std::string& s)
{
    return s.size() < 5;
}

int main()
{
    std::vector<std::string> v;
    std::string s;
    
    std::cout << "Enter a string: ";
    while (std::cin >> s)
        v.push_back(s);
    auto it = std::partition(v.begin(), v.end(), has_less_than_five_char);
    
    while (it != v.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
    
    return 0;
}
