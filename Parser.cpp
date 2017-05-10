//
//  Parser.cpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Parser.hpp"


std::deque<std::string> Parser::tokenize(const std::string& rawInput) {
    std::deque<std::string> tokens;
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


S_Expression Parser::process_syntax (std::deque<std::string>& tokens) {
    if (tokens.size()==0) {
        throw "Syntax Error!";
    }
    std::string token;
    tokens.pop_front();
    if (tokens[0] == ")") {
        throw "Syntax Error!";
    } else if (tokens[0] == "(") {  //expression
        std::deque<std::string> temp;
        int i = 0;
        while (tokens[i]!=")" && tokens[i]!="(") {
            temp.push_back(tokens[i]);
            ++i;
        }
        
    } else {    //atom
        
    }
    
}

