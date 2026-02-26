/*
 * Exercise 9.4: Write a function that takes a pair of iterators to a vector<int> and an
 * int value. Look for that value in the range and return a bool indicating whether it
 * was found.
 * 
 * Exercise 9.5: Rewrite the previous program to return an iterator to the requested element.
 * Note that the program must handle the case where the element is not found.
 */
 
#include <vector>
#include <iostream>

bool contains(std::vector<int>::iterator begin, std::vector<int>::iterator end, const int target)
{
    while (begin != end)
    {
        if (*begin == target)
            return true;
        ++begin;
    }
    return false;
}

std::vector<int>::iterator find(std::vector<int>::iterator begin, std::vector<int>::iterator end, const int target)
{
    while (begin != end)
    {
        if (*begin == target)
            return begin;
        ++begin;
    }
    return end;
}

int main()
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a = -1, b = 3;
    
    // Exercise 9.4
    std::cout << "The vector " << (contains(v.begin(), v.end(), a) ? "contains " : "does not contain ")
              << a << ".\n";
    std::cout << "The vector " << (contains(v.begin(), v.end(), b) ? "contains " : "does not contain ")
              << b << ".\n";
              
    // Exercise 9.5
    auto ita = find(v.begin(), v.end(), a);
    if (ita != v.end())
        std::cout << "The vector contains " << a << " at position " << ita - v.begin() << ".\n";
    else
        std::cout << "The vector does not contain " << a << ".\n";
    auto itb = find(v.begin(), v.end(), b);
    if (itb != v.end())
        std::cout << "The vector contains " << b << " at position " << itb - v.begin() << ".\n";
    else
        std::cout << "The vector does not contain " << b << ".\n";
    
    return 0;
}
