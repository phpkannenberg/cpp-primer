/*
 * Exercise 10.15: Write a lambda that captures an int from its enclosing function and
 * takes an int parameter. The lambda should return the sum of the captured int and
 * the int parameter.
 */
 
#include <iostream>

int main()
{
    int five = 5;
    auto sum5 = [five] (int a) -> int { return five + a; };
    
    std::string cont = "y";    
    do
    {
        std::cout << "Enter a integer: ";
        int a;
        std::cin >> a;
        std::cout << five << " + " << a << " = " << sum5(a) << "\n";
        std::cout << "Would you like to continue? [y/n] ";
        std::cin >> cont;
    } while (cont == "y");
    
    return 0;
}
