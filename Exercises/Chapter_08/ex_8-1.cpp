/*
 * Exercise 8.1: Write a function that takes and returns an istream&. The function
 * should read the stream until it hits end-of-file. The function should print what it reads
 * to the standard output. Reset the stream so that it is valid before returning the stream.
 *
 * Exercise 8.2: Test your function by calling it, passing cin as an argument.
 */
 
#include <iostream>
#include <string>

std::istream &read_until_eof(std::istream& is)
{
    std::string s;
    
    while (is >> s)
    {
        std::cout << s << " ";
    }
    
    std::cout << "\n";
    
    is.clear();
    return is;
}

int main()
{
    read_until_eof(std::cin);
    return 0;
}
