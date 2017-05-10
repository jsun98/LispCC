//
//  Cell.hpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-10.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

#include "S_Expression.hpp"

class Cell {
public:
    Cell();
    virtual ~Cell();
    size_t size() const;
    void push (S_Expression* se);
    
    
private:
    std::vector<S_Expression*> ss;
    
    
    
};

#endif /* Cell_hpp */
