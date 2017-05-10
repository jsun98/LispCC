//
//  S_Expression.hpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-09.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef S_Expression_hpp
#define S_Expression_hpp

#include <vector>
#include <string>

class S_Expression {
public:
    S_Expression(std::vector<std::string>& s);
    virtual ~S_Expression();
    void push(std::string& str);
    void print();
    void clear();
    size_t size();
    std::vector<std::string> value();
private:
    std::vector<std::string> s;
protected:
    
    
};

#endif /* S_Expression_hpp */
