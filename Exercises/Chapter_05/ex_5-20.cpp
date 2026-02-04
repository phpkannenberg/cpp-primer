/*
 * Exercise 5.20:
 * Write a program to read a sequence of strings from the standard input until either the same
 * word occurs twice in succession or all the words have been read. Use a while loop to read the
 * text one word at a time. Use the break statement to terminate the loop if a word occurs twice
 * in succession. Print the word if it occurs twice in succession, or else print a message
 * saying that no word was repeated.
 */
 
#include <string>
#include <iostream>

using namespace std;

int main() {
  bool repeated = false;
  string prev, cur;
  
  cout << "Enter some words: ";  
  while (cin >> cur) {
    if (cur == prev) {
      repeated = true;
      break;
    }
    prev = cur;
  }
  
  if (repeated) {
    cout << "\nThe word '" << cur << "' occurred twice in succession." << endl; 
  } else {
    cout << "\nNo words occurred twice in succession." << endl;
  }
  
  return 0;
}
