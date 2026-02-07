/* 
 * Exercise 6.33: Write a recursive function to print the contents of a vector.
 */
 
#include <vector>
#include <iostream>

void print_vector(const std::vector<int> &v, const decltype(v.size()) idx = 0) 
{
  if (idx == v.size()) {
    return;
  } else if (idx == 0) {
    std::cout << "\nVector: ";
  }
  
  std::cout << v[idx] << " ";
  print_vector(v, idx + 1);
}

int main() 
{
  std::vector<int> v;
  int n;
  
  std::cout << "Enter some integers: ";
  while (std::cin >> n) {
    v.push_back(n);
  }
  
  print_vector(v);
  std::cout << std::endl;
  
  return 0;
}
