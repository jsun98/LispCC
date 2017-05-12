//
//  SchemeNamespace.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-11.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "SchemeNamespace.hpp"

SchemeNamespace::SchemeNamespace () {
    global_env["+"] = &(SchemeNamespace::add);
}

SList* SchemeNamespace::add (const SList*& argv)  {
    double dVal = 0.0;
    listType v = argv->getList();
    for (auto vi = v.cbegin(); vi != v.cend(); vi++) {
        dVal += atof((*vi)->val().c_str());
    }
    return new SList(dVal);
}


