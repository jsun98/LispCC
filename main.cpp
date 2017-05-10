//
//  main.cpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Parser.hpp"
#include "FormattedIO.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    while (true) {
        string line;
        line = FormattedIO::readLine();
        vector<string> tokens = Parser::tokenize(line);
        for (int i = 0 ; i < tokens.size(); i++) {
            cout << tokens[i] << endl;
        }
    }
    return 0;
}
