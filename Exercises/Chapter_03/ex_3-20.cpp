/*
 * Read a set of integers into a vector. Print the sum of each pair of adjacent elements.
 * Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.
 */

#include <vector>
#include <iostream>

using std::vector;

int main() {
  vector<int> v;
  int n = 0;
  
  // Reads a set of integers into a vector
  std::cout << "Enter a set of integers: ";
  while (std::cin >> n) {
    v.push_back(n);
  }

  // Prints the sum of each pair of adjacent elements
  if (!v.empty() && v.size() > 1) {
    std::cout << "\nFirst sum: ";
    for (decltype(v.size()) i = 0; i < v.size() - 1; i++) {
      std::cout << v[i] + v[i + 1] << " ";
    }
  } else {
    std::cout << "\nNot possible to compute the first sum" << std::endl;
  }
  
  // Prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on
  if (!v.empty()) {
    std::cout << "\nSecond sum: ";
    for (decltype(v.size()) i = 0; i <= v.size() / 2; i++) {  // when v.size() is odd, prints the sum of the mid term plus the mid term
      std::cout << v[i] + v[v.size() - 1 - i] << " ";
    }
  } else {
    std::cout << "\nNot possible to compute the second sum" << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
