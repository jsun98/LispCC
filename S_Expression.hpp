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

class S_Expression {
public:
    S_Expression();
    virtual ~S_Expression();
    void push();
    void print();
    size_t size();
private:
    std::vector<std::string> s;
    void clear();
protected:
    
    
};

#endif /* S_Expression_hpp */
