#include <string>
#include "Person.h"

std::istream &read(std::istream &is, Person &person)
{
    std::getline(is, person.name);
    std::getline(is, person.address);
    return is;
}

std::ostream &print(std::ostream& os, const Person& person)
{
    os << person.get_name() << " " << person.get_address();
    return os;
}

Person::Person(std::istream &is)
{
    read(is, *this);
}

Person::Person(const std::string &n, const std::string &a) : 
               name(n), address(a) { }

const std::string &Person::get_name() const 
{
    return name;
}

const std::string &Person::get_address() const
{
    return address;
}
