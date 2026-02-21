/*
 * Exercise 8.4: Write a function to open a file for input and read its contents into a 
 * vector of strings, storing each line as a separate element in the vector.
 *
 * Exercise 8.5: Rewrite the previous program to store each word in a separate element.
 */
 
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

void read_line_into_vector(std::ifstream &ifstrm, std::vector<std::string> &v) 
{
    std::string s;
    while (getline(ifstrm, s))
        v.push_back(s);
}

void read_word_into_vector(std::ifstream &ifstrm, std::vector<std::string> &v)
{
    std::string s;
    while (ifstrm >> s)
        v.push_back(s);
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        std::cerr << "Use: " << argv[0] << " filename" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::vector<std::string> v1, v2;
    std::ifstream ifstrm;

    // Test read_line_into_vector 
    ifstrm.open(filename);
    read_line_into_vector(ifstrm, v1);
    ifstrm.close();
    for (auto s : v1)
        std::cout << s << "\n";
    std::cout << "\n";
    
    // Test read_word_into_vector
    ifstrm.open(filename);
    read_word_into_vector(ifstrm, v2);
    ifstrm.close();
    for (auto s : v2)
        std::cout << s << "\n";
    std::cout << "\n";
    
    return 0;
}
