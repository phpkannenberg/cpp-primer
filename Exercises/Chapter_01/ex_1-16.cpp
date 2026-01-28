/*
Exercise 1.16: Write your own version of a program that prints the sum of a set of integers read from cin.
*/

#include <iostream>

int main() {
  int n1, n2, sum = 0;
  std::cout << "Enter two integer number: " << std::endl;
  std::cin >> n1 >> n2;
  
  if (n1 <= n2) {
    for (int i = n1; i <= n2; i++)
      sum += i;
  } else {
    for (int i = n2; i <= n1; i++)
      sum += i;
  }
  
  std::cout << "The sum of the numbers from " << (n1 < n2 ? n1 : n2) << " to " << (n1 < n2 ? n2 : n1) << " is " << sum << "." << std::endl;
  return 0;
}
