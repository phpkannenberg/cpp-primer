/*
 * Exercise 3.17: 
 * Read a sequence of words from cin and store the values in a vector.
 * After you've read all the words, process the vector and change each word to uppercase.
 * Print the transformed elements, eight words to a line.
 */

#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using std::vector;
using std::string;

int main() {
  vector<string> v;
  string s;
  
  // Reads all the words and stores them in the vector
  while (std::cin >> s) {
    v.push_back(s);
  }
  std::cout << std::endl;
  
  if (!v.empty()) {
    // Processes the vector and changes each word to uppercase
    for (auto &s : v) {
      for (auto &c : s) {
        c = std::toupper(c);
      }
    }
    
    // Prints the transformed elements, eight words to a line
    vector<string>::size_type word_count = 0;
    while (word_count != v.size()) {
      std::cout << v[word_count] << (word_count % 8 == 7 ? "\n" : " ");
      ++word_count;
      if (word_count == v.size())  // makes sure there's a line break after the last word
        std::cout << std::endl;
    }
  } else {
    std::cout << "No strings were inserted." << std::endl;
  }

  return 0;
}
