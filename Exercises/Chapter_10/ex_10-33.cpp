/*
 * Exercise 10.33: Write a program that takes the names of an input file and two output
 * files. The input file should hold integers. Using an istream_iterator read the 
 * input file. Using ostream_iterator, write the odd numbers into the first output
 * file. Each value should be followed by a space. Write the even numbers into the second
 * file. Each of these values should be placed on a separate file.
 */
 
#include <iterator>
#include <fstream>
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Use: " << argv[0] << "input_filename output_filename1 output_filename2" 
                  << std::endl;
        return EXIT_FAILURE;
    }
    
    std::ifstream numbers(argv[1]);
    std::ofstream odds(argv[2]), 
                  evens(argv[3]);
                  
    if (!numbers || !odds || !evens)
    {
        std::cerr << "Error opening files" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::istream_iterator<int> in_iter(numbers);
    std::istream_iterator<int> eof;
    
    std::ostream_iterator<int> odds_out(odds, " ");
    std::ostream_iterator<int> evens_out(evens, "\n");
    
    while (in_iter != eof)
    {
        if (*in_iter % 2 != 0)
            *odds_out++ = *in_iter;
        else
            *evens_out++ = *in_iter;
        
        ++in_iter;
    }
    
    return EXIT_SUCCESS;
}
