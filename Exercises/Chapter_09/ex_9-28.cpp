/*
 * Exercise 9.28: Write a function that takes a forward_list<string> and two additional 
 * string arguments. The function should find the first string and insert the
 * second immediately following the first. If the first string is not found, then insert the
 * second string at the end of the list.
 */
 
#include <forward_list>
#include <string>
#include <iostream>

void insert_after_string(std::forward_list<std::string> &lst, const std::string &first, const std::string &second)
{
    auto prev = lst.before_begin(), 
         curr = lst.begin(),
         end = lst.end();
    while (curr != end)
    {
        if (*curr == first)
        {
            lst.insert_after(curr, second);
            break;
        }
        prev = curr;
        ++curr;
    }
    if (curr == end)
        lst.insert_after(prev, second);
}

void print_flst(const std::forward_list<std::string> &lst)
{
    for (auto elem : lst)
        std::cout << elem << " ";
}

int main()
{
    std::forward_list<std::string> lst{"one", "two", "three", "four", "five"};
    
    insert_after_string(lst, "zero", "six");
    print_flst(lst);
    std::cout << "\n";
    
    insert_after_string(lst, "one", "one_point_five");
    print_flst(lst);
    std::cout << "\n";
    
    return 0;
}
