/*
 * Exercise 10.35: Now print the elements in reverse order using ordinary iterators.
 */
 
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> numbers{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    auto it = numbers.end();
    while (it != numbers.begin())
    {
        --it;
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
