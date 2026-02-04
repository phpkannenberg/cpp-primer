/*
 * Exercise 5.19:
 * Write a program that uses a do while loop to repetitively request two strings from the
 * user and report which string is less than the other.
 */
 
#include <iostream>
#include <string>

using std::string;
using std::cin; using std::cout; using std::endl;

int main() {
  string s1, s2;
  char cont = 'y';
  do {
    // Requests the two strings
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    
    // Compares the strings
    if (s1 != s2) {
      cout << (s1 < s2 ? s1 : s2) << " is less than " << (s1 < s2 ? s2 : s1) << "." << endl;
    } else {
      cout << "The two strings are identical." << endl;
    }
    
    // Requests to continue
    cout << "Continue? [y/n]: ";
    cin >> cont;
  } while (cont == 'y' || cont == 'Y');
  return 0;
}
