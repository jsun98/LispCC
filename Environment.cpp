//
//  Environment.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-15.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Environment.hpp"

Environment::Environment () : outerEnv(nullptr) {}

Environment::Environment (SLists params, SLists args, Environment* outerEnv) : outerEnv(outerEnv) {
    auto a = args.cbegin();
    for (auto vi = params.cbegin(); vi != params.cend(); vi++) {
        env[(*vi).val()] =  (*a++);
    }
    
}

envType* Environment::find (symbol s) {
    if (env.find(s)!=env.end()) {
        return &env;
    }  else {
        if (outerEnv==nullptr) {
            return nullptr;
        } else {
            return outerEnv->find(s);
        }
    }
}
