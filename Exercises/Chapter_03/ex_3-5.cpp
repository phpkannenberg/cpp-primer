/*
 * Write a program to read strings from the standard input, concatenating what is read into one large string.
 * Print the concatenated string. Next, change the program to separate adjacent strings by a space.
 */
 
#include <iostream>
#include <string>

int main() {
  std::string temp, conc;
  std::cout << "Enter your strings: ";

  while (std::cin >> temp) {
    conc += temp;
    conc += " ";  // the last character appended will always be a space character
  }
  
  std::cout << '\n' << conc << std::endl;
  return 0;
}
