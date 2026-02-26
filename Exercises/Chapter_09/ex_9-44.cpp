/*
 * Exercise 9.44: Rewrite the previous function using an index and replace.
 */
 
#include <string>
#include <iostream>

void replace_all_instances(std::string& s, 
                           const std::string& oldVal, 
                           const std::string& newVal)
{
    if (oldVal.size() == 0)
        return;
    
    decltype(s.size()) i = 0;
    while (i != s.size())
    {
        if (s[i] == oldVal[0])  // first character match
        {
            auto s_i = i;
            auto ov_i = 0;
            while (s_i != s.size() && ov_i != oldVal.size())
            {
                if (s[s_i] != oldVal[ov_i])
                    break;
                ++s_i;
                ++ov_i;
            }
            
            if (ov_i == oldVal.size())  // full match
            {
                s.replace(i, oldVal.size(), newVal);
                i += newVal.size();
            }
            else  // partial match
            {
                ++i;
            }
        }
        else  // no match
        {
            ++i;
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
