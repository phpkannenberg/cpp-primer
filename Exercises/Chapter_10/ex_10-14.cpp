/*
 * Exercise 10.14: Write a lambda that takes two ints and returns their sum.
 */
 
#include <iostream>

int main()
{
    auto sum = [] (int a, int b) -> int { return a + b; };
    
    std::string cont = "y";    
    do
    {
        std::cout << "Enter two integers: ";
        int a, b;
        std::cin >> a >> b;
        std::cout << a << " + " << b << " = " << sum(a, b) << "\n";
        std::cout << "Would you like to continue? [y/n] ";
        std::cin >> cont;
    } while (cont == "y");
    
    return 0;
} 
