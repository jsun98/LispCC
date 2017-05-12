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

#include "Primitive_Procs.hpp"
#include "SList.hpp"


typedef std::string symbol;
typedef SList* (*proc)(const std::vector<SList*>&);

class SchemeNamespace {
public:
    virtual ~SchemeNamespace();
    
    virtual void restoreDefault() final;
private:
    
protected:
    SchemeNamespace();
    std::unordered_map<symbol, proc> global_env;
    
    
    
    
    
    
};

#endif /* SchemeNamespace_hpp */
