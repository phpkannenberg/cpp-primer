/*
 * Exercise 12.30: Define your own versions of the TextQuery and QueryResult
 * classes and execute the runQuerries function from 12.3.1.
 *
 * Exercise 12.33: In Chapter 15 we'll extend our query system and will need some 
 * additional members in the QueryResult class. Add members named begin and end that
 * return iterators into the set of line numbers returned by a given query, and a member
 * named get_file that returns a shared_ptr to the file in the QueryResult object.
 */

#include "TextQuery.h"
#include "QueryResult.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

void runQuerries(std::ifstream &infile)
{
    TextQuery tq(infile);
    
    while (true) 
    {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Use: " << argv[0] << " filename" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::ifstream infile(argv[1]);
    if (!infile)
    {
        std::cerr << "Error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    
    runQuerries(infile);
    
    return EXIT_SUCCESS;
}
