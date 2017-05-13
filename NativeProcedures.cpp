//
//  NativeProcedures.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-12.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "NativeProcedures.hpp"

SList add (SLists argv)  {
    double dVal = 0.0;
    for (auto vi = argv.begin(); vi != argv.end(); vi++)
        dVal += atof((*vi).val().c_str());
    return SList(std::to_string(dVal), SList::NUMBER);
}
