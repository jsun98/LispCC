//
//  SList.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-10.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "SList.hpp"

SList::SList(sType type) : type(type) {;}
SList::SList(std::string s) : type(SYMBOL), strAtom(s) {;}
SList::SList(int s) : type(INTEGER), intAtom(s) {;}
SList::SList(double s) : type(FLOAT), doubleAtom(s) {;}
SList::SList(SList* s) : type(LIST)  {
    list.push_back(s);
}

//recursively delete all lists
SList::~SList() {
    if (type==LIST)
        for (auto vi = list.cbegin(); vi != list.cend(); vi++) delete *vi;
}

void SList::push(SList* s) {
    list.push_back(s);
}

std::string SList::getPrintString() const {
    std::string s = "";
    if (type == SYMBOL)
        s+=strAtom + " ";
    else if (type == INTEGER)
        s+=std::to_string(intAtom) + " ";
    else if (type == FLOAT)
        s+=std::to_string(doubleAtom) + " ";
    else {
        s+="(";
        for (auto vi = list.cbegin(); vi != list.cend(); vi++)
            s+=(*vi)->getPrintString();
        if (s.back() == ' ') s.pop_back();
        s+=")";
    }
    return s;
}
