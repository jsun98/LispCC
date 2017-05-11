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
#include <stdlib.h>
#include <deque>
#include <string>

class Parser {
public:
    static SList* parse (const std::string rawInput) ;
    
    virtual ~Parser();
private:
    Parser();
    static std::deque<std::string> tokenize(const std::string rawInput);
    static SList* process_syntax (std::deque<std::string>& tokens);
    static SList* atomic (std::string s);
    static bool isNumber (std::string s);
    static bool isInteger (std::string s);
};

#endif /* Parser_hpp */
