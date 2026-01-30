/*
 * Write a program to define an array of ten ints. Give each element the same value as its position in the array.
 */
 
#include <iostream>
 
int main() {
  int a[10];
  
  for (int i = 0; i < 10; i++) 
    a[i] = i;
  
  for (int n : a)
    std::cout << n << " ";
    
  std::cout << std::endl;
  
  return 0;
}
