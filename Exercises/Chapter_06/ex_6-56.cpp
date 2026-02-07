/*
 * Exercise 6.55: Write four functions that add, subtract, multiply, and divide two int
 * values. Store pointers to these functions in your vector from the previous exercise.
 * 
 * Exercise 6.56: Call each element in the vector and print their result.
 */
 
#include <vector>
#include <iostream>
#include <stdexcept>

int add(int a, int b) 
{
  return a + b;
}

int subtract(int a, int b)
{
  return a - b;
}

int multiply(int a, int b)
{
  return a * b;
}

int divide(int a, int b)
{
  if (b == 0) 
    throw std::runtime_error("Division by zero undefined.");
  return a / b;
}

int main()
{
  std::vector<int (*)(int, int)> v = {add, subtract, multiply, divide};
  
  int a, b;
  std::cout << "Enter two integers: ";
  std::cin >> a >> b;
  
  for (auto f : v) {
    try { 
      std::cout << f(a, b) << std::endl;
    } catch (std::runtime_error e) {
      std::cout << e.what() << std::endl;
    }
  }
  
  return 0;
}
