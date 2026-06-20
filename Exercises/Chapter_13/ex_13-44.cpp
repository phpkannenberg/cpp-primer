/*
 * Exercise 13.44: Write a class named String that is a simplified version of the library
 * string class. Your class should have at least a default constructor and a constructor
 * that takes a pointer to a C-style string. Use an allocator to allocate memory that 
 * your string class uses.
 */
 
#include <cstdlib>
#include <memory>
#include <utility>
 
class String
{
public:
    String(): 
        elements(nullptr), end(nullptr) { }
    String(const char*);
    String(const String&);
    String &operator=(const String&);
    ~String();
    
    const char *begin_iter() const { return elements; };
    const char *end_iter() const { return end; }
    std::size_t size() const { return end - elements; }
    bool empty() const { return elements == end; }
private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();
    
    static std::allocator<char> alloc;
    char *elements;
    char *end;
};

std::allocator<char> String::alloc;

String::String(const char* s)
{
    // increments end until it finds the end of c style string
    const char *e = s;
    while (*e != '\0') 
        ++e;
    
    // allocatens new memory and update pointers
    auto data = alloc_n_copy(s, e);
    elements = data.first;
    end = data.second;
}

String::String(const String& s)
{
    auto data = alloc_n_copy(s.elements, s.end);
    elements = data.first;
    end = data.second;
}

String &String::operator=(const String& rhs)
{
    auto data = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = data.first;
    end = data.second;
    return *this;
}

String::~String()
{
    free();
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void String::free()
{
    if (elements)
    {
        auto num_elements = end - elements;
        while (end != elements)
            alloc.destroy(--end);
        alloc.deallocate(elements, num_elements);
    }
    elements = end = nullptr;
}
