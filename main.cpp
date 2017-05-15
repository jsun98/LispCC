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
typedef std::unordered_map<symbol, SList> envType;


SLists getArgs (SList l) {
    SLists unproc_args = l.getList();
    SLists args;
    for (int i = 1; i < unproc_args.size(); i++) {
        args.push_back(unproc_args[i]);
    }
    return args;
}

SList evaluate (SList s, envType& env) {
    if (s.getType() == SList::SYMBOL) {             //variable reference
        return env[s.val()];
    } else if (s.getType() == SList::NUMBER) {      //const literal
        return s;
    } else {                                        //procedure call
        if (s.getList()[0].val() == "define") {
            return env[s.getList()[1].val()] = evaluate(s.getList()[2],env);
        } else {
            SLists args = getArgs(s);
            for (int i = 0; i < args.size(); i++)
                args[i] = evaluate (args[i],env);
            SList::proc p = evaluate(s.getList()[0],env).getProc();
            return p(args);
        }
    }
}


void env_setup (envType& global_env) {
    global_env.insert({"+",SList(&add,SList::PROC)});
    global_env.insert({"-",SList(&subtract,SList::PROC)});
    global_env.insert({"*",SList(&multiply,SList::PROC)});
    global_env.insert({"/",SList(&divide,SList::PROC)});
    global_env.insert({"mod",SList(&mod,SList::PROC)});
    global_env.insert({"sqrt",SList(&sqrt,SList::PROC)});
    global_env.insert({"sin",SList(&sin,SList::PROC)});
    global_env.insert({"cos",SList(&cos,SList::PROC)});
    global_env.insert({"tan",SList(&tan,SList::PROC)});
    global_env.insert({"asin",SList(&arcsin,SList::PROC)});
    global_env.insert({"acos",SList(&arccos,SList::PROC)});
    global_env.insert({"atan",SList(&arctan,SList::PROC)});
    global_env.insert({"abs",SList(&abs,SList::PROC)});
}

int main(int argc, const char * argv[]) {
    envType global_env;
    env_setup (global_env);
    while (true) {
        string line;
        line = FormattedIO::readLine();
        //cout << list.getPrintString() << endl;
        cout << evaluate(Parser::parse(line), global_env).getPrintString() << endl;
    }
    return 0;
}
