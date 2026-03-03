/*
 * Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive, into three
 * other containers. Use an inserter, a back_inserter, and a front_inserter,
 * respectively to add elements to these containers. 
 */
 
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> d1, d2, d3;
    
    std::copy(v.begin(), v.end(), std::inserter(d1, d1.begin()));
    std::copy(v.begin(), v.end(), std::back_inserter(d2));
    std::copy(v.begin(), v.end(), std::front_inserter(d3));
    
    auto print = [] (int a) { std::cout << a << " "; };
    
    std::cout << "inserter:       ";
    std::for_each(d1.begin(), d1.end(), print);
    std::cout << "\n";
    
    std::cout << "back_inserter:  ";
    std::for_each(d2.begin(), d2.end(), print);
    std::cout << "\n";
    
    std::cout << "front_inserter: ";
    std::for_each(d3.begin(), d3.end(), print);
    std::cout << "\n";
    
    return 0;
}
 

