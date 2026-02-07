/*
 * Exercise 6.25: Write a main function that takes two arguments. Concatenate the supplied
 * arguments and print the resulting string.
 */
 
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 3)
      throw logic_error("Number of arguments must be equal to 2");
  string s1 = argv[1]; 
  string s2 = argv[2];
  string conc = s1 + s2;
  cout << conc << endl;
  return 0;
}
