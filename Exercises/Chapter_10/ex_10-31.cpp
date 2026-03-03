/*
 * Exercise 10.30: Use stream iterators, sort, and copy to read a sequence of integers
 * from the standard input, sort them, and then write them back to the standard output.
 *
 * Exercise 10.31: Update the program from the previous exercise so that it prints only
 * the unique elements. Your program should use unique_copy.
 */
 
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::istream_iterator<int> in(std::cin); 
    std::istream_iterator<int> eof;
    
    std::vector<int> numbers(in, eof);
    std::sort(numbers.begin(), numbers.end());
    
    std::cout << "\n";
    std::ostream_iterator<int> out(std::cout, " ");
    std::unique_copy(numbers.begin(), numbers.end(), out);
    std::cout << std::endl;
    
    return 0;
}
