//
//  STD_IN.cpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "FormattedIO.hpp"

std::string FormattedIO::readLine() {
    std::string line = "";
    getline(std::cin,line);
    return line;
}
