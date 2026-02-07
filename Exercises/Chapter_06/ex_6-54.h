/*
 * Exercise 6.54: Write a declaration for a function that takes two int parameters and
 * returns an int, and declare a vector whose elements have this function pointer type.
 */
 
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

int f(int, int);
extern std::vector<int (*)(int, int)> v;

#endif
