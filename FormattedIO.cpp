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
    std::cout << ":>> ";
    getline(std::cin,line);
    return line;
}

std::string FormattedIO::readLicense() {
    std::string fn = "./LICENSE";
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
