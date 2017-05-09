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
#include <vector>

class parser {
public:
    static std::vector<std::string> parse () ;
private:
    parser();
    static std::vector<std::string> tokenize(const std::string& rawInput);
    static std::vector<std::string> process_syntax (const std::vector<std::string>& tokens);
};

#endif /* Parser_hpp */
