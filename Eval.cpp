//
//  Eval.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-11.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Eval.hpp"

SList* Eval::evaluate (const SList* s, envType env) {
    listType v = s->getList();
    SList* token = v.front();
    v.pop_front();
    
    if (token->getType() == SList::SYMBOL) {
        if (env.find(token->val())!=env.cend()) {   //proc
            SList* temp = new SList(v);
            proc f = env[token->val()];
            return f(temp);
        }
    } else {
        
    }
    
    return nullptr;
    
    
}
