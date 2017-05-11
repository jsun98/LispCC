//
//  SList.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-10.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "SList.hpp"


SList::SList(std::string s) : type(STRING), strAtom(s) {;}
SList::SList(long int s) : type(INTEGER), intAtom(s) {;}
SList::SList(long double s) : type(FLOAT), doubleAtom(s) {;}
SList::SList(SList* s) : type(LIST), list(s)  {;}

SList::~SList() {
    if (type==LIST)
        for (auto vi = list.cbegin(); vi != list.cend(); vi++) delete *vi;
}

void SList::push(SList* s) {
    
}
