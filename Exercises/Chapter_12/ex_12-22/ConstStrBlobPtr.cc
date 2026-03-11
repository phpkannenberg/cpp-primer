#include "ConstStrBlobPtr.h"
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

const std::string& ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

std::shared_ptr<const std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();  // is the vector still around?
    if (!ret)
        throw std::runtime_error("unbound ConstStrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}
