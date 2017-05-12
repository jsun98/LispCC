//
//  SchemeNamespace.hpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-11.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef SchemeNamespace_hpp
#define SchemeNamespace_hpp

#include <unordered_map>
#include <string>
#include <stdlib.h>
#include "SList.hpp"


typedef std::string symbol;
typedef SList* (*proc)(const SList*& argv);
typedef std::unordered_map<symbol, proc> envType;



class SchemeNamespace {
public:
    virtual ~SchemeNamespace();
    static envType global_env;
private:
    static SList* add (const SList*& argv);
protected:
    SchemeNamespace();
    
    
};

#endif /* SchemeNamespace_hpp */
