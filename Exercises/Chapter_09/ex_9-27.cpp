/*
 * Exercise 9.27: Write a program to find and remove the odd-valued elements in a 
 * forward_list<int>.
 */
 
#include <forward_list>
#include <iostream>

int main()
{
    std::forward_list<int> lst;
    
    auto it = lst.before_begin();
    for (int i = 0; i < 10; ++i)
        it = lst.insert_after(it, i);
    
    auto prev = lst.before_begin(),
         curr = lst.begin();
    while (curr != lst.end())
    {
        if (*curr % 2 != 0)
        {
            curr = lst.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }
    
    for (auto i : lst)
        std::cout << i << " ";
    std::cout << std::endl;
    
    return 0;
}
