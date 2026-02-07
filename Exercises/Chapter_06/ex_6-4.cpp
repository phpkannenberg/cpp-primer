/*
 * Exercise 6.4: Write a function that interacts with the user, asking for a number and
 * generating the factorial of that number. Call this function from main.
 */
 
#include <iostream>
#include <stdexcept>
using namespace std;

void factorial() {
  long long n;
  cout << "Enter a non-negative integer: ";
  cin >> n;
  
  if (n < 0) {
    throw runtime_error("Factorial of negative integer undefined.");
  }
  
  long long result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;  // Doesn't check for overflow
  }
  
  cout << n << "! = " << result << endl;  
}

int main() {
  try {
    factorial();
  } catch (runtime_error e) {
    cout << e.what() << endl;
  }
  return 0;
}
