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
#include "NativeProcedures.hpp"

#include <unordered_map>


using namespace std;

typedef std::string symbol;
typedef SList (*proc)(SLists argv);
typedef std::unordered_map<symbol, proc> envType;

SLists getArgs (SList l) {
    SLists unproc_args = l.getList();
    SLists args;
    for (int i = 1; i < unproc_args.size(); i++) {
        args.push_back(unproc_args[i]);
    }
    return args;
}

SList evaluate (SList s, envType env) {
    if (s.getType() == SList::SYMBOL) {             //variable reference
        return SList(env[s.val()],SList::PROC);
    } else if (s.getType() == SList::NUMBER) {      //const literal
        return SList(s.val(),SList::NUMBER);
    } else {                                        //procedure call
        proc p = evaluate(s.getList()[0],env).getProc();
        SLists args = getArgs(s);
        for (int i = 0; i < args.size(); i++) args[i] = evaluate (args[i],env);
        return p(args);
    }
}

void env_setup (envType& native_env) {
    native_env["+"] = &add;
}

int main(int argc, const char * argv[]) {
    envType native_env;
    env_setup (native_env);
    while (true) {
        string line;
        line = FormattedIO::readLine();
        SList list(Parser::parse(line));
        cout << list.getPrintString() << endl;
        cout << evaluate(list, native_env).getPrintString() << endl;
    }
    return 0;
}
