//
//  SList.hpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-10.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef SList_hpp
#define SList_hpp

#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>

#ifdef _M_X64
typedef int64_t int_t;
#define a_to_int_t  atoll
#else
typedef long int_t;
#define a_to_int_t  atoi
#endif


#include <iostream>



class SList {
public:
    typedef SList (*proc)(const std::vector<SList>&);
    enum sType {SYMBOL, NUMBER, LIST, PROC, LAMBDA};
    
    void push(SList s);
    std::string getPrintString() const;
    size_t size() const;
    sType getType() const;
    void setType(sType t);
    std::string val() const;
    std::vector<SList> getList () const;
    std::string listToString();
    proc getProc() const;
    void pushList(std::vector<SList> s);
    std::string getTypeString() const;
    
    SList();
    SList(sType type);
    SList(std::string s);
    SList(double s);
    SList(std::vector<SList> s);
    SList(proc s);
private:
    std::string value;
    std::vector<SList> list;
    proc p;
    
    sType type;
    
    
};

typedef std::vector<SList> SLists;

#endif /* SList_hpp */
