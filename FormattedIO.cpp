//
//  STD_IN.cpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "FormattedIO.hpp"

std::vector<std::string> formattedIO::readLine() {
    std::string token = "";
    std::vector<std::string> line;
    while (std::cin >> token) {
        line.push_back(token);
    }
    return line;
}
