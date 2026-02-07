/*
 * Exercise 6.7: Write a function that returns 0 when it is first called and then generates
 * numbers in sequence each time it is called again.
 */
 
#include <iostream>
using namespace std;

int number_of_calls() {
  static int n = 0;
  return ++n;
}

int main() {
  int n;
  cout << "Enter number of iterations: ";
  cin >> n;
  if (n < 1) 
    cout << "Number must be greater than 1." << endl;
  for (int i = 1; i <= n; ++i) {
    cout << "Iteration #" << i << ": " << number_of_calls() << endl;
  }
  return 0;
}
