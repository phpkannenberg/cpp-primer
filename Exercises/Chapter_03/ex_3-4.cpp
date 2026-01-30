/*
 * Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger.
 * Now, change the program to report whether the strings have the same length, and if not, report which is longer.
 */
 
#include <iostream>
#include <string>

int main() {
  std::string s1, s2;
  std::cout << "Enter two strings: ";
  std::cin >> s1 >> s2;
  
  if (s1.size() == s2.size()) {
    std::cout << "The two string have the same size." << std::endl;
  } else {
    std::cout << (s1.size() > s2.size() ? s1 : s2) << " is longer than " << (s1.size() > s2.size() ? s2 : s1) << "." << std::endl;
  }
  
  return 0;
}
