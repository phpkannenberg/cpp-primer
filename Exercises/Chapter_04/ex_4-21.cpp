/*
 * Exercise 4.21:
 * Write a program to use a conditional operator to find the elements in a vector<int> 
 * that have odd value and double the value of each such element.
 */
 
#include <vector>
#include <iostream>
using std::vector;

int main() {
  // List initialization of the vector
  vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  // Doubles the value of the element if element value is odd
  for (int &n : v) {
    n = (n % 2 == 0) ? n : n * 2;
  }
  
  // Prints the resulting vector
  for (int n : v) {
    std::cout << n << " ";
  }
  
  return 0;
}
