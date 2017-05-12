//
//  Eval.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-11.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include <unordered_map>
#include <string>
#include "SList.hpp"

#include <unordered_map>
#include <string>
#include <stdlib.h>
#include <vector>
#include "SList.hpp"

typedef std::string symbol;
typedef SList (*proc)(SList argv);
typedef std::unordered_map<symbol, proc> envType;

envType native_env;

SList add (SList argv)  {
    double dVal = 0.0;
    listType v = argv.getList();
    for (auto vi = v.begin(); vi != v.end(); vi++) {
        dVal += atof((*vi).val().c_str());
    }
    return SList(std::to_string(dVal), SList::NUMBER);
}

void env_setup () {
    native_env["+"] = &add;
}

listType getArgs (listType l) {
    listType n;
    for (int i = 1; i < l.size(); i++) {
        n.push_back(l[i]);
    }
    return n;
}

SList evaluate (SList s, envType env) {
    listType v = s.getList();
    SList token = v.front();
    
    if (token.getType() == SList::SYMBOL) {
        if (env.find(token.val())!=env.cend()) {   //proc
            proc f = env[token.val()];
            SList temp(getArgs(v), SList::LIST);
            return f(temp);
        }
    } else {
        
    }
    
    return s;
    
    
}

