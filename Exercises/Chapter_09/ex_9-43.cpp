/*
 * Exercise 9.43: Write a function that takes three strings, s, oldVal, and newVal.
 * Using iterators, and the insert and erase functions replace all instances of oldVal
 * that appear in s by newVal. 
 */
 
#include <string>
#include <iostream>

void replace_all_instances(std::string& s, 
                           const std::string& oldVal, 
                           const std::string& newVal)
{
    if (oldVal.size() == 0)
        return;
    
    auto it = s.begin();
    while (it != s.end())
    {
        if (*it == *oldVal.begin())  // first characters match
        {
            auto s_it = it;
            auto ov_it = oldVal.begin();     
            while (s_it != s.end() && ov_it != oldVal.end())
            {
                if (*s_it != *ov_it)
                    break;
                ++s_it;
                ++ov_it;
            }
            
            if (ov_it == oldVal.end())  // full match
            {
                it = s.erase(it, s_it);
                it = s.insert(it, newVal.begin(), newVal.end());
                it += newVal.size();
            }
            else  // partial match
            {
                ++it;
            }
        }
        else  // no match
        {
            ++it;
        }
    }
}

int main()
{
    std::string s = "1.2.3.4.5.";
    replace_all_instances(s, ".", "...");
    std::cout << s << std::endl;
    return 0;
}
