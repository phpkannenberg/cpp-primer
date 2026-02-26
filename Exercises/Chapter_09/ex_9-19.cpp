/*
 * Exercise 9.19: Rewrite the program from the previous exercise to use a list. List the
 * changes you needed to make.
 */
 
#include <iostream>
#include <list>
#include <string>

int main()
{
    std::string str;
    std::list<std::string> lst;
    
    // Reads a sequence of strings from the standard input into a list
    while (std::cin >> str)
        lst.push_back(str);
    
    // Uses iterators to write a loop to print the elements in the list
    for (auto it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    return 0;
}

