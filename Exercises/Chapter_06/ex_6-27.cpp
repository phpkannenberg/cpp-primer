/*
 * Write a function that takes an initializer_list<int> and produces
 * the sum of the elements in the list.
 */
 
#include <iostream>
#include <initializer_list>
using namespace std;

int sum(const initializer_list<int> it) {
  int sum = 0;
  for (auto n : it) {
    sum += n;
  }
  return sum;
}

int main() {
  initializer_list<int> it{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int result = sum(it);
  cout << result << endl;
  return 0;
}
