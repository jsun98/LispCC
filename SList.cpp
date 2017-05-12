//
//  SList.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-10.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "SList.hpp"

SList::SList(std::string s, sType t) : value(s) , type(t) {;}
SList::SList(SList s, sType t) : type(t)  {list.push_back(s);}
SList::SList(listType s, sType t) : type(t)  {list = s;}

void SList::push(SList s) {
    list.push_back(s);
}

SList::sType SList::getType() const {
    return type;
}

listType SList::getList () const {
    return list;
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
        s+=")";
    }
    return s;
}
