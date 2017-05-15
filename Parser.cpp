//
//  Parser.cpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Parser.hpp"

SList Parser::parse(const std::string rawInput) {
    std::deque<std::string> temp = tokenize(rawInput);
    return process_syntax(temp);
}


std::deque<std::string> Parser::tokenize(const std::string rawInput) {
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


SList Parser::process_syntax (std::deque<std::string>& tokens) {
    if (tokens.size()==0) throw "Syntax Error: Unexpected End of Line";
    std::string token = tokens[0];
    tokens.pop_front();
    if (token == "(") { //expression
        SList list ("",SList::LIST);
        while (tokens[0]!=")") {
            list.push(process_syntax(tokens));
        }
        tokens.pop_front();
        return list;
    } else if (token == ")") {
        throw "Syntax Error: Unexpected Syntax ')'";
    } else {    //atom
        return atomic(token);
    }
}

SList Parser::atomic (std::string s) {
    if (isNumber(s)) {
        return SList(s.c_str(), SList::NUMBER);  //double/float
    }
    return SList(s, SList::SYMBOL);    //symbol
}

bool Parser::isNumber (std::string s) {
    return s.find_first_not_of( "0123456789." ) == std::string::npos;
}

bool Parser::isInteger (std::string s) {
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
    char * p ;
    strtol(s.c_str(), &p, 10) ;
    return (*p == 0) ;
}

