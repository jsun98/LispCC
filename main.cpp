//
//  main.cpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "Parser.hpp"
#include "SList.hpp"
#include "FormattedIO.hpp"
#include "SchemeNamespace.hpp"
#include "Eval.hpp"
#include "SchemeNamespace.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    while (true) {
        SchemeNamespace* env = new SchemeNamespace;
        string line;
        line = FormattedIO::readLine();
        SList* list = Parser::parse(line);
        cout << list->getPrintString() << endl;
        cout << Eval::evaluate(list, global_env)->val() << endl;
    }
    return 0;
}
