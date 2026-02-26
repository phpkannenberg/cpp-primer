/*
 * Exercise 9.49: A letter has an ascender if, as with d or f, part of the letter extends 
 * above the middle of the line. A letter has a descender if, as with p or g, part of the
 * letter extends below the line. Write a program that reads a file containing words and
 * reports the longest word that contains neither ascenders nor descenders.
 */
 
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

const std::string asc_desc = "bdfghjklpqty";

// valid only for lowercase alphabetical characters
std::string longest_flat(std::ifstream& ifs)
{
    std::string curr, longest;
    while (ifs >> curr)
    {
        auto pos = curr.find_first_of(asc_desc);
        if (pos == std::string::npos)
            longest = (curr.size() > longest.size()) ? curr : longest;
    }
    return longest;
}

int main(int argc, char **argv) 
{
    if (argc != 2)
    {
        std::cerr << "Use: " << argv[0] << " filename" << std::endl;
        return EXIT_FAILURE;
    }   
    
    std::ifstream ifs(argv[1]);
    if (!ifs)
    {
        std::cerr << "Could't open file." << std::endl;
        return EXIT_FAILURE;
    }
    
    std::cout << "Longest flat word is: " << longest_flat(ifs) << ".\n";
    
    return EXIT_SUCCESS;
}
