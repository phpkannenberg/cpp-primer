/*
 * Exercise 6.12: Rewrite the program from exercise 6.10 to use references
 * instead of pointers to swap the value of two ints.
 */

#include <iostream>
using namespace std;

void swap_ints(int &n1, int &n2) {
  int temp = n1;
  n1 = n2;
  n2 = temp;
}

int main() {
  int n1 = 1, n2 = 2;
  cout << "n1 = " << n1 << "; n2 = " << n2 << endl;
  swap_ints(n1, n2);
  cout << "n1 = " << n1 << "; n2 = " << n2 << endl;
  return 0;
}
