#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include "TextQuery.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <set>

std::ostream& print(std::ostream&, const QueryResult&);

class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) { }
        
        std::set<TextQuery::line_no>::const_iterator begin() const
            { return lines->begin(); }
        std::set<TextQuery::line_no>::const_iterator end() const
            { return lines->end(); }
        
        std::shared_ptr<const std::vector<std::string>> get_file() const
            { return file; }

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif
