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
#include "S_Expression.hpp";
#include "Cell.hpp";

#include <deque>

class Parser {
public:
    static std::deque<std::string> parse () ;
    
    virtual ~Parser();
private:
    Parser();
    static std::deque<std::string> tokenize(const std::string& rawInput);
    static Cell process_syntax (std::deque<std::string>& tokens);
};

#endif /* Parser_hpp */
