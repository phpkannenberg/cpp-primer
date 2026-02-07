#include "Chapter6.h"
#include <stdexcept>

long long factorial(int n) {
  if (n < 0) {
    throw std::runtime_error("Undefined operation for negative values.");
  }
  
  long long result = 1;
  for (int i = 2; i <= n; ++i) {
    result *= i;  // Does not check for overflow
  }
  
  return result;
}
