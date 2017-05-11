//
//  Parser.hpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include "FormattedIO.hpp"
#include "SList.hpp"
#include <deque>

class Parser {
public:
    static std::deque<std::string> parse () ;
    
    virtual ~Parser();
private:
    Parser();
    static std::deque<std::string> tokenize(const std::string& rawInput);
    static SList* process_syntax (std::deque<std::string>& tokens);
    static SList* atomic (std::string s);
    static SList* atomic (long int s);
    static SList* atomic (long double s);
};

#endif /* Parser_hpp */
