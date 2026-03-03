/*
 * Exercise 10.16: Write your own version of the biggies function using lambdas.
 *
 * Exercise 10.18: Rewrite biggies to use partition instead of find_if.
 *
 * Exercise 10.19: Rewrite the previous exercise to use stable_partition, which like
 * stable_sort maintains the original element order in the partitioned sequence.
 */
 
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

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
                        [sz] (const std::string &a)
                             { return a.size() < sz; });
    
    auto count = words.end() - wc;
    std::cout << count << " word(s) of length " << sz << " or longer" 
              << std::endl;
    std::for_each(wc, words.end(),
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
