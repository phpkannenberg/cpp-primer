/*
 * Exercise 11.31: Write a program that defines a multimap of authors and their works.
 * Use find to find an element in the multimap and erase that element. Be sure your 
 * program works correctly if the element you look for is not in the map.
 *
 * Exercise 11.32: Using the multimap from the previous exercise, write a program to
 * print the list of authors and their works alphabetically.
 */
 
#include <map>
#include <string>
#include <iostream>

int main()
{
    std::multimap<std::string, std::string> authors;
    
    authors.insert({"Hermann Hesse", "Der Steppenwolf"});
    authors.insert({"Hermann Hesse", "Siddhartha"});
    authors.insert({"Thomas Mann", "Die Buddenbrooks"});
    authors.insert({"Thomas Mann", "Der Zauberberg"});
    authors.insert({"Aldous Huxley", "Brave New World"}); 
    authors.insert({"Aldous Huxley", "The Island"});
    authors.insert({"Bjarne Stroustrup", "A Tour of C++"});
    
    std::string author, title;
    std::cout << "Author: ";
    std::getline(std::cin, author);
    std::cout << "Title: ";
    std::getline(std::cin, title);
    
    auto range = authors.equal_range(author);
    if (range.first == range.second)
    {
        std::cout << "No entries for author: " << author << std::endl;
    } 
    else
    {
        while (range.first != range.second)
        {
            if (range.first->second == title)
                break;
            ++range.first;
        }
        if (range.first != range.second)
        {
            authors.erase(range.first);
            std::cout << "\"" << title << "\" by " << author 
                      << " was successfully erased.\n"; 
        }
        else
        {
            std::cout << author << " has no title: " << title << std::endl;
        }
    }
    
    std::cout << "\nAvailable:\n";
    auto it = authors.begin();
    while (it != authors.end())
    {
        auto range = authors.equal_range(it->first);

        std::cout << it->first << ":\n";
        auto cur_title = range.first;
        while (cur_title != range.second)
        {
            std::cout << '\t' << cur_title->second << '\n';
            ++cur_title;
        }
        
        it = range.second;
    }
    
    return 0;
}
