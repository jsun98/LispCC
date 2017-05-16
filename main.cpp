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
#include "Environment.hpp"

#include <unordered_map>


using namespace std;


SLists getArgs (SList l) {
    SLists unproc_args = l.getList();
    SLists args;
    for (int i = 1; i < unproc_args.size(); i++) {
        args.push_back(unproc_args[i]);
    }
    return args;
}

SList evaluate (SList s, Environment& env) {
    if (s.getType() == SList::SYMBOL) {             //variable reference
        return env.env[s.val()];
    } else if (s.getType() == SList::NUMBER) {      //constant literal
        return s;
    } else if (s.getList()[0].getType() == SList::SYMBOL) {         //special form
        if (s.getList()[0].val() == "define") {
            return env.env[s.getList()[1].val()] = evaluate(s.getList()[2],env);
        } else if (s.getList()[0].val() == "lambda") {
            
            
        } else {
            return SList();
        }
    } else {            //procedure call
        SLists args = getArgs(s);
        for (int i = 0; i < args.size(); i++)
            args[i] = evaluate (args[i],env);
        SList::proc p = evaluate(s.getList()[0],env).getProc();
        return p(args);
    }
}


void env_setup (Environment& std_env) {
    std_env.env.insert({"+",SList(&add)});
    std_env.env.insert({"-",SList(&subtract)});
    std_env.env.insert({"*",SList(&multiply)});
    std_env.env.insert({"/",SList(&divide)});
    std_env.env.insert({"mod",SList(&mod)});
    std_env.env.insert({"sqrt",SList(&sqrt)});
    std_env.env.insert({"sin",SList(&sin)});
    std_env.env.insert({"cos",SList(&cos)});
    std_env.env.insert({"tan",SList(&tan)});
    std_env.env.insert({"asin",SList(&arcsin)});
    std_env.env.insert({"acos",SList(&arccos)});
    std_env.env.insert({"atan",SList(&arctan)});
    std_env.env.insert({"abs",SList(&abs)});
}

int main(int argc, const char * argv[]) {
    Environment std_env;
    env_setup (std_env);
    while (true) {
        string line;
        line = FormattedIO::readLine();
        //cout << list.getPrintString() << endl;
        cout << evaluate(Parser::parse(line), std_env).getPrintString() << endl;
    }
    return 0;
}
