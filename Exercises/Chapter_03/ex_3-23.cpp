/*
 * Write a program to create a vector with ten int elements. Using an iterator, assign each
 * element a value that is twice its current value. Test your program by printing the vector.
 */
 
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
  vector<int> v;
  
  // Populates the vector with ints from 1 to 10
  for (int i = 1; i <= 10; i++)
    v.push_back(i);
    
  // Multiplies each element by two
  for (auto it = v.begin(); it != v.end(); ++it)
    *it *= 2;
  
  // Prints each element from the vector
  for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";

  cout << endl;
  return 0;
}
