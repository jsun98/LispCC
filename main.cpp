//
//  main.cpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "FormattedIO.hpp"
#include "SList.hpp"
#include "Parser.hpp"
#include "Eval.cpp"


using namespace std;


int main(int argc, const char * argv[]) {
    while (true) {
        string line;
        line = FormattedIO::readLine();
        SList list(Parser::parse(line));
        cout << list.getPrintString() << endl;
        env_setup();
        cout << evaluate(list, native_env).getPrintString() << endl;
    }
    return 0;
}
