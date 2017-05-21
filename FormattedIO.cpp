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
    if (line.find_first_not_of(" ")==std::string::npos)
        return "";
    else
        return line;
}

std::string FormattedIO::readFile(std::string fileName) {
    std::string fn = fileName;
    std::ifstream rawFile (fn.c_str());
    std::string rawText = "";
    std::string line = "";
    while (!rawFile.eof()) {
        std::getline(rawFile,line);
        rawText += line+"\n";
    }
    rawFile.close();
    return rawText;
}

