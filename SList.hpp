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

class SList {
public:
    void push(SList* s);
    std::string getPrintString() const;
    void clear();
    size_t size() const;
    std::vector<std::string> getList () const;
    enum sType {SYMBOL, INTEGER, FLOAT, LIST};
    sType getType() const;
    
    int getVal_i();
    double getVal_f();
    
    
    SList(sType type);
    SList(std::string s);
    SList(int s);
    SList(double s);
    SList(SList* s);
    virtual ~SList();
private:
    std::string strAtom;
    int intAtom;
    double doubleAtom;
    std::vector<SList*> list;
    sType type;
    
    
};

#endif /* SList_hpp */
