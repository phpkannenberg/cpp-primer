/*
 * Exercise 10.25: In the exercises for 10.3.2 you wrote a version of biggies
 * that uses partition. Rewrite that function to use check_size and bind.
 */
 
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std::placeholders;

bool check_size(const std::string &s, std::string::size_type sz)
{
    return s.size() >= sz;
}

// Put words in alphabetical order and remove duplicates 
void elimDups(std::vector<std::string> &words)
{
   std::sort(words.begin(), words.end());
   auto end_unique = unique(words.begin(), words.end());
   words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), 
                [] (const std::string &a, const std::string &b)
                   { return a.size() < b.size(); });
    auto wc = std::stable_partition(words.begin(), words.end(),
                                    std::bind(check_size, _1, sz));
    
    auto count = words.end() - wc;
    std::cout << count << " word(s) of length " << sz << " or longer." 
              << std::endl;
    std::for_each(words.begin(), wc,
                  [] (const std::string &s) { std::cout << s << " "; });
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> words;
    
    std::string word;
    while (std::cin >> word)
        words.push_back(word);
    
    biggies(words, 5);
    
    return 0;
}
