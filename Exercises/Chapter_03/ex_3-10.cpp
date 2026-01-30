/*
 * Exercise 3.10: Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.
 */

#include <string>
#include <iostream>
#include <cctype>

int main() {
  std::string s, result;
  std::cin >> s;
  
  for (auto c : s) {
    if (!std::ispunct(c)) {
      result += c;
    }
  }
  
  std::cout << result << std::endl;
  
  return 0;
}
