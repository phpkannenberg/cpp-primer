/*
 * Exercise 5.23: Write a program that reads two integers from the standard input and
 * prints the result of dividing the first number by the second.
 * 
 * Exercise 5.24: Revise your program to throw an exception if the second number is
 * zero. Test your program with a zero input to see what happens on your system if you
 * don't catch an exception.
 * 
 * Exercise 5.25: Revise your program from the previous exercise to use a try block to
 * catch the exception. The catch clause should print a message to the user and ask
 * them to supply a new number and repeat the code inside the try. 
 */
 
#include <iostream>
#include <exception>
using namespace std;

int main() {
  int n1, n2;
  
  while (true) {
    cout << "Enter two integers: ";
    cin >> n1 >> n2;
    try {
      if (n2 == 0) {
        throw runtime_error("Invalid input. Division by zero not allowed.");
      }
      cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
      break;
    } catch (runtime_error e) {
      cout << e.what() << " Please try again. \n";
    }
  }
  
  return 0;
}
