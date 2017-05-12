//
//  Primitive_Procs.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-11.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Primitive_Procs.hpp"

SList* add (const std::vector<SList*>& argv) {
    if (argv.size() == 0) throw "Must Provide Arguments!";
    SList::sType type = SList::INTEGER;
    int i_val = 0;
    double d_val = 0.0;
    for (auto vi = argv.cbegin(); vi != argv.cend(); vi++) {
        if ((*vi)->getType()==SList::FLOAT) {
            throw "Uncaught Evaluation Exception!";
        } else if ((*vi)->getType()==SList::FLOAT) {
            type = SList::FLOAT;
            d_val += (*vi)->getVal_f() + i_val;
        } else {
            i_val += (*vi)->getVal_i();
        }
    }
    SList* result;
    if (type==SList::INTEGER) result = new SList(i_val);
    else result = new SList(d_val);
    return result;
}
