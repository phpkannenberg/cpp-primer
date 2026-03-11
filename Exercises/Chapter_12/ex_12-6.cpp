/*
 * Exercise 12.6: Write a function that returns a dynamically allocated vector of ints.
 * Pass that vector to another function that reads the standard input to give values to
 * the elements. Pass the vector to another function to print the values that were read.
 * Remember to delete the vector at the appropriate time.
 */
 
#include <vector>
#include <iostream>

std::vector<int>* make_vec()
{
    return new std::vector<int>();
}

void fill_vec(std::vector<int>* v) 
{
    std::cout << "Enter some integers: ";
    int i;
    while (std::cin >> i)
        v->push_back(i);
}

void print_vec(const std::vector<int>* v)
{
    for (auto const& elem : *v)
        std::cout << elem << " ";
}

int main()
{
    std::vector<int> *v = make_vec();
    fill_vec(v);
    std::cout << '\n';
    print_vec(v);
    std::cout << '\n';
    delete v;
    return 0;
}
