/*
 * Exercise 12.7: Redo the previous exercise, this time using shared_ptr.
 */
 
#include <vector>
#include <iostream>
#include <memory>

std::shared_ptr<std::vector<int>> make_vec()
{
    return std::make_shared<std::vector<int>>();
}

void fill_vec(std::shared_ptr<std::vector<int>> sp) 
{
    std::cout << "Enter some integers: ";
    int i;
    while (std::cin >> i)
        sp->push_back(i);
}

void print_vec(const std::shared_ptr<std::vector<int>> sp)
{
    for (auto const& elem : *sp)
        std::cout << elem << " ";
}

int main()
{
    auto sp = make_vec();
    fill_vec(sp);
    std::cout << '\n';
    print_vec(sp);
    std::cout << '\n';
    return 0;
}
