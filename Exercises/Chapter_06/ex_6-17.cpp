/*
 * Exercise 6.17: Write a function to determine whether a string contains any capital 
 * letters. Write a function to change a string to all lowercase.
 */
 
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

bool contains_uppercase(const string &s) {
  bool result = false;
  for (auto c : s) {
    if (isupper(c)) {
      result = true;
      break;
    }
  }
  return result;
}

string to_lowercase(const string &s) {
  string lower;
  for (auto c : s) {
    lower += tolower(c);
  }
  return lower;
}

int main() {
  string s;
  cout << "Enter a string: ";
  cin >> s;
  
  cout << s << " contains " << (contains_uppercase(s) ? "" : "no ") 
       << "uppercase letter(s)." << endl;
  cout << s << " to all lowercase is " << to_lowercase(s) << "." << endl;
  
  return 0;
}
