//
//  SList.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-10.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "SList.hpp"

SList::SList() {};
SList::SList(std::string s, sType t) : value(s) , type(t) {;}
SList::SList(SLists s, sType t) : type(t)  {list = s;}
SList::SList(proc s, sType t) : p(s) , type(t) {;}


void SList::push(SList s) {
    list.push_back(s);
}

SList::sType SList::getType() const {
    return type;
}

SLists SList::getList () const {
    return list;
}

SList::proc SList::getProc() const {
    return p;
}

std::string SList::val() {return value;}

//for debugging
std::string SList::getPrintString() const {
    std::string s = "";
    if (type != LIST)
        s+=value + " ";
    else {
        s+="(";
        for (auto vi = list.cbegin(); vi != list.cend(); vi++)
            s+=(*vi).getPrintString();
        if (s.back() == ' ') s.pop_back();
        s+=") ";
    }
    return s;
}
