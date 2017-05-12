//
//  Eval.hpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-11.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef Eval_hpp
#define Eval_hpp

#include <unordered_map>
#include <string>
#include "SList.hpp"
#include "SchemeNamespace.hpp"

class Eval {
public:
    static SList* evaluate (const SList* s, std::unordered_map<std::string, proc> env);
    
    
};



#endif /* Eval_hpp */
