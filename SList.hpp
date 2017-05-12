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
    enum sType {SYMBOL, NUMBER, LIST};
    
    void push(SList s);
    std::string getPrintString() const;
    size_t size() const;
    std::vector<SList> getList () const;
    sType getType() const;
    
    std::string val();

    SList(std::string s, sType t);
    SList(SList s, sType t);
    SList(std::vector<SList> s, sType t);
private:
    std::string value;
    std::vector<SList> list;
    
    sType type;
    
    
};

typedef std::vector<SList> listType;

#endif /* SList_hpp */
