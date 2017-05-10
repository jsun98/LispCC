//
//  Parser.cpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Parser.hpp"

std::vector<std::string> Parser::tokenize(const std::string& rawInput) {
    std::vector<std::string> tokens;
    for (int i = 0; i < rawInput.length(); ++i) {
        while (rawInput[i] == ' ') ++i;
        if (rawInput[i] == '(') tokens.push_back("(");
        else if (rawInput[i] == ')') tokens.push_back(")");
        else {
            int j = i;
            while (rawInput[j] && rawInput[j] != ')' && rawInput[j] != '(' && rawInput[j] != ' ')
                ++j;
            tokens.push_back(rawInput.substr(i,j-i));
            i = j-1;
        }
    }
    return tokens;
}


std::vector<std::string> Parser::process_syntax (const std::vector<std::string>& tokens) {
    if (tokens.size()==0)
        throw "Syntax Error!";
    if (tokens[0] == ")") {
        throw "Syntax Error!";
    } else if (tokens[0] == "(") {  //expression
        int i = 0;
        while (tokens[i]!=')') {
            
        }
        
    } else {    //atom
        
    }
    
}

