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


SList* Parser::process_syntax (std::deque<std::string>& tokens) {
    if (tokens.size()==0) throw "Syntax Error!";
    std::string token = tokens[0];
    tokens.pop_front();
    if (tokens[0] == "(") { //expression
        SList* expr = nullptr;
        while (tokens[0]!=")") {
            if (expr)
                expr->push(process_syntax(tokens));
            else
                expr = new SList(process_syntax(tokens));
        }
    } else if (token == ")") {
        throw "Syntax Error!";
    } else {    //atom
        
    }
}

