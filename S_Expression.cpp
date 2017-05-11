//
//  S_Expression.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-09.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "S_Expression.hpp"

S_Expression::S_Expression() {};
S_Expression::S_Expression(std::string s) { this->s.push_back(s); }
S_Expression::S_Expression(std::vector<std::string> s) : s(s) {};

std::vector<std::string> S_Expression::getExpression() const { return s; }

size_t S_Expression::size() const { return s.size(); }
