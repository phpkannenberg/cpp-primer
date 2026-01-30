/*
 * Exercise 3.6: Write a range for to change all the characters in a string to X.
 */

#include <string>
#include <iostream>

int main() {
  std::string some_string = "Some String";
  
  for (auto &c : some_string) {
    c = 'X';
  }
  
  std::cout << some_string << std::endl;
  
  return 0;
}
