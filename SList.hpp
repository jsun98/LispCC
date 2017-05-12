//
//  SList.hpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-10.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef SList_hpp
#define SList_hpp

#include <deque>
#include <string>



class SList {
public:
    enum sType {SYMBOL, INTEGER, FLOAT, LIST};
    
    void push(SList* s);
    std::string getPrintString() const;
    size_t size() const;
    std::deque<SList*> getList () const;
    sType getType() const;
    
    std::string val();

    SList(std::string s);
    SList(int s);
    SList(double s);
    SList(SList* s);
    virtual ~SList();
private:
    std::string strAtom;
    int intAtom;
    double doubleAtom;
    std::deque<SList*> list;
    
    sType type;
    
    
};

typedef std::deque<SList*> listType;

#endif /* SList_hpp */
