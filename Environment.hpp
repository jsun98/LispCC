//
//  Environment.hpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-15.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef Environment_hpp
#define Environment_hpp
#include <unordered_map>
#include "SList.hpp"

typedef std::string symbol;
typedef std::unordered_map<symbol, SList> envType;

class Environment {
public:
    Environment ();
    virtual ~Environment();
private:
    envType env;
    Environment* outerEnv;
};
#endif /* Environment_hpp */
