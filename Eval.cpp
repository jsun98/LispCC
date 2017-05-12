//
//  Eval.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-11.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Eval.hpp"

SList* Eval::evaluate (SList* s, envType env) {
    listType v = s->getList();
    if (s->getType() == SList::SYMBOL) {
        if (env.find(v[0]->val())!=env.cend()) {
            proc f = env[v[0]->val()];
            *f(new std::vector(v.cbegin()+1,v.cend()));
        }
    } else {
        
    }
    
    
}
