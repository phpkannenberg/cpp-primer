/*
 * Exercise 10.27: In addition to unique, the library defines function named
 * unique_copy that takes a third iterator denoting a destination into which
 * to copy the unique elements. Write a program that uses unique_copy to copy
 * the unique elements from a vector into an initially empty list.
 */
 
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> ints{0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> unique_ints;
    
    std::sort(ints.begin(), ints.end());
    std::unique_copy(ints.begin(), ints.end(), std::back_inserter(unique_ints));
    
    std::for_each(unique_ints.begin(), unique_ints.end(),
                  [] (int a) { std::cout << a << " "; });
    std::cout << std::endl;
    
    return 0;
}
