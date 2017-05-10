//
//  Cell.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-10.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Cell.hpp"

Cell::~Cell() {
    for (auto vi = ss.cbegin() ; vi != ss.cend(); vi++)
        delete *vi;
}

size_t Cell::size() const {
    return ss.size();
}

void Cell::push(S_Expression* se) {
    ss.push_back(se);
}
