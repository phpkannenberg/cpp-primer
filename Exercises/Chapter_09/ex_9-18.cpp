/*
 * Exercise 9.18: Write a program to read a sequence of strings from the standard input
 * into a deque. Use iterators to write a loop to print the elements in the deque.
 */
 
#include <iostream>
#include <deque>
#include <string>

int main()
{
    std::string str;
    std::deque<std::string> deq;
    
    // Reads a sequence of strings from the standard input into a deque
    while (std::cin >> str)
        deq.push_back(str);
    
    // Uses iterators to write a loop to print the elements in the deque
    for (auto it = deq.begin(); it != deq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    return 0;
}
