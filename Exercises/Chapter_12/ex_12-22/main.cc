/*
 * Exercise 12.19: Define your own version of StrBlobPtr and update your StrBlob 
 * class with the appropriate friend declaration and begin and end members.
 *
 * Exercise 12.20: Write a program that reads an input file a line at a time into a StrBlob
 * and uses a StrBlobPtr to print each element in that StrBlob.
 */
 
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "StrBlob.h"
#include "StrBlobPtr.h"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Use: " << argv[0] << " filename";
        return EXIT_FAILURE;
    }
    
    std::ifstream ifstrm(argv[1]);
    if (!ifstrm)
    {
        std::cerr << "Could not open file";
        return EXIT_FAILURE;
    }
    
    std::string line;
    StrBlob blob;
    
    while (std::getline(ifstrm, line))
        blob.push_back(line);
    
    StrBlobPtr bp(blob);
    bool done = false;
    int line_count{1};
    while (!done)
    {
        try
        {
            std::string curr = bp.deref();
            std::cout << "Line " << line_count++ << ": " << curr << "\n";
            bp.incr();
        }
        catch (const std::out_of_range &e)
        {
            done = true;
        }
    }
    
    return EXIT_SUCCESS;
}
