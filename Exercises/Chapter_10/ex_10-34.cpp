/*
 * Exercise 10.34: Use reverse_iterators to print a vector in reverse order.
 */
 
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> numbers{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = numbers.crbegin(); it != numbers.crend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    return 0;
}
