/*
 * Exercise 13.39: Write your own version of StrVec, including versions of reserve,
 * capacity, and resize.
 *
 * Exercise: 13.40: Add a constructor that takes an initializer_list<string> to
 * your StrVec class.
 *
 * Exercise 13.43: Rewrite the free member to use for_each and a lambda
 * in place of the for loop to destroy the elements.
 */
 
 #include <memory>
 #include <string>
 #include <cstdlib>
 #include <initializer_list>
 #include <utility>
 #include <algorithm>
 
 class StrVec
 {
 public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(std::initializer_list<std::string>);
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();
    void push_back(const std::string&);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    void reserve(const std::size_t);
    void resize(const std::size_t);
    void resize(const std::size_t, const std::string&);
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
 };
 
 std::allocator<std::string> StrVec::alloc;
 
 void StrVec::push_back(const std::string& s)
 {
    chk_n_alloc();
    alloc.construct(first_free++, s);
 }
 
 std::pair<std::string*, std::string*> 
 StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements)
    {
        std::for_each(elements, first_free, [] (std::string &s) { alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    auto pair = alloc_n_copy(il.begin(), il.end());
    elements = pair.first;
    first_free = cap = pair.second;
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() 
{ 
    free(); 
} 
 
StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{    
    reserve(size() ? size() * 2 : 0);
}

void StrVec::reserve(const std::size_t newcapacity)
{
    if (newcapacity <= capacity()) return;
    
    // allocate new memory
    auto newdata = alloc.allocate(newcapacity);
    
    // transfer data from old memory to new memory
    auto dest = newdata;
    auto elem = elements;
    for (std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    
    // free old memory
    free();
    
    // update pointers
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::resize(const std::size_t count)
{
    if (count > size())
    {
        reserve(count);
        while (size() < count)
            alloc.construct(first_free++, std::string());
    }
    
    else if (count < size())
    {
        while (size() > count)
            alloc.destroy(--first_free);
    }
}
    
void StrVec::resize(const std::size_t count, const std::string& value)
{
    if (count > size())
    {
        reserve(count);
        while (size() < count)
            alloc.construct(first_free++, value);
    }
    
    else if (count < size())
        while (size() > count)
            alloc.destroy(--first_free);
}
