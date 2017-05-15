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
    typedef SList (*proc)(std::vector<SList> argv);
    enum sType {SYMBOL, NUMBER, LIST};
    
    void push(SList s);
    std::string getPrintString() const;
    size_t size() const;
    sType getType() const;
    
    std::string val();
    std::vector<SList> getList () const;
    proc getProc() const;
    
    SList();
    SList(std::string s, sType t);
    SList(std::vector<SList> s, sType t);
    SList(proc s, sType t);
private:
    std::string value;
    std::vector<SList> list;
    proc p;
    
    sType type;
    
    
};

typedef std::vector<SList> SLists;

#endif /* SList_hpp */
