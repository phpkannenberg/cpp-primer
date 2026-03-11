/*
 * Exercise 12.22: What changes would need to be made to StrBlobPtr to create a class 
 * that can be used with a const StrBlob? Define a class named ConstStrBlobPtr
 * that can point to a const StrBlob.
 */

#ifndef CONST_STR_BLOB_PTR_H
#define CONST_STR_BLOB_PTR_H

#include <string>
#include <vector>
#include <memory>
#include <cstddef>
#include "StrBlob.h"

class ConstStrBlobPtr 
{
public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0):
        wptr(a.data), curr(sz) { }
    
    const std::string& deref() const;
    ConstStrBlobPtr& incr();  // prefix version
    
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<const std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    
    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    
    // current position within the array
    std::size_t curr;
};

#endif
