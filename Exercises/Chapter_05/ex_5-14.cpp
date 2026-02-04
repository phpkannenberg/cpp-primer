/*
 * Exercise 5.14:
 * Write a program to read strings from standard input looking for duplicated words. The program should
 * find places in the input where one word is followed immediately by itself. Keep track of the largest
 * number of times a single repetition occurs and which word is repeated. Print the maximum number of 
 * duplicates, or else print a message saying that no word was repeated.
 */
 
#include <string>
#include <iostream>

using std::string;
using std::cin; using std::cout; using std::endl;

int main() {
  string most_reps,
         prev, 
         cur;
  unsigned int max_reps = 1, 
               cur_reps = 0;
  
  // Reads the sequence of words and updates variables values
  while (cin >> cur) {
    if (cur == prev) {
      ++cur_reps;
    } else {
      if (cur_reps > max_reps) {
        most_reps = prev;
        max_reps = cur_reps;
      }
      prev = cur;
      cur_reps = 1;
    }
  }
  
  // In case the last sequence of repeated words was the longest
  if (cur_reps > max_reps) {
    most_reps = prev;
    max_reps = cur_reps;
  }
  
  // Prints the final result
  if (max_reps > 1) {
    cout << "\nThe most repeated word was: " << most_reps <<  ". It was repeated " << max_reps << " times." << endl;
  } else {
    cout << "\nNo words were repeated." << endl;
  }
  
  return 0;
}
