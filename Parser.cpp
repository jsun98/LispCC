//
//  Parser.cpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Parser.hpp"

std::vector<std::string> parser::tokenize(const std::string& rawInput) {
    std::vector<std::string> tokens;
    for (int i = 0; i < rawInput.length(); ++i) {
        if (rawInput[i] == '(') tokens.push_back("(");
        else if (rawInput[i] == ')') tokens.push_back(")");
        else {
            int j = i;
            while (rawInput[j] && rawInput[j] != ')' && rawInput[j] != '(' && rawInput[j] != ' ')
                ++j;
            tokens.push_back(rawInput.substr(i,j-i));
            i = j;
        }
    }
    return tokens;
}

/*
std::vector<std::string> parser::process_syntax (const std::vector<std::string> tokens){
    if (tokens.size()==0)
        std::cerr<< "Syntax Error" << std::endl;
    
    if (tokens[0] == "(") {
        
    } else if (tokens[0] == ")") {
        
    } else {
        
    }
    
}
*/
