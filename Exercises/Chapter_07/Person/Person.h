/*
 * Exercise 7.4: Write a class named Person that represents the name and address of
 * a person. Use a string to hold each of these elements. Subsequent exercised will
 * incrementally add features to this class.
 *
 * Exercise 7.5: Provide operations in your Person class to return the name and
 * address. Should these functions be const? Explain your choice.
 *
 * Exercise 7.9: Add operations to read and print Person objects to the code you wrote
 * for the exercises in 7.1.2.
 *
 * Exercise 7.15: Add appropriate constructors to your Person class.
 * 
 * Exercise 7.22: Update your Person class to hide its implementation.
 */
 
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
friend std::istream &read(std::istream&, Person&);

private:
    std::string name;
    std::string address;
    
public:
    Person() = default;
    Person(std::istream &is);
    Person(const std::string &n, const std::string &a = "");
    const std::string &get_name() const;
    const std::string &get_address() const;
};

std::istream &read(std::istream& is, Person& person);
std::ostream &print(std::ostream& os, const Person& person);

#endif
