/*
 * Exercise 9.20: Write a program to copy elements from a list<int> into two deques.
 * the even-valued elements should go into one deque and the odd ones into the other.
 */
 
#include <list>
#include <deque>
#include <iostream>

int main()
{
    std::list<int> lst;
    for (int i = 0; i < 100; ++i)
        lst.push_back(i);
    
    std::deque<int> even, odd;
    for (auto i : lst) 
    {
        if (i % 2 == 0)
            even.push_back(i);
        else
            odd.push_back(i);
    }
    
    std::cout << "Even: ";
    for (auto i : even)
        std::cout << i << " ";
    
    std::cout << "\nOdd: ";
    for (auto i : odd)
        std::cout << i << " ";
    std::cout << std::endl;
    
    return 0;
}
