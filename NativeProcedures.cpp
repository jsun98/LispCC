//
//  NativeProcedures.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-12.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "NativeProcedures.hpp"

SList add (const SLists& argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal += atof((*vi).val().c_str());
    return SList(std::to_string(dVal));
}

SList subtract (const SLists& argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal -= atof((*vi).val().c_str());
    return SList(std::to_string(dVal));
}

SList multiply (const SLists& argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal *= atof((*vi).val().c_str());
    return SList(std::to_string(dVal));
}

SList divide (const SLists& argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal /= atof((*vi).val().c_str());
    return SList(std::to_string(dVal));
}

SList mod (const SLists& argv)  {
    int iVal = atoi(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        iVal %= atoi((*vi).val().c_str());
    return SList(std::to_string(iVal));
}

SList sqrt (const SLists& arg)  {
    return SList(std::to_string(sqrt(atof(arg[0].val().c_str()))));
}

SList sin (const SLists& arg)  {
    return SList(std::to_string(sin(atof(arg[0].val().c_str()))));
}

SList cos (const SLists& arg)  {
    return SList(std::to_string(cos(atof(arg[0].val().c_str()))));
}

SList tan (const SLists& arg)  {
    return SList(std::to_string(tan(atof(arg[0].val().c_str()))));
}

SList arcsin (const SLists& arg)  {
    return SList(std::to_string(asin(atof(arg[0].val().c_str()))));
}

SList arccos (const SLists& arg)  {
    return SList(std::to_string(acos(atof(arg[0].val().c_str()))));
}

SList arctan (const SLists& arg)  {
    return SList(std::to_string(atan(atof(arg[0].val().c_str()))));
}

SList abs (const SLists& arg) {
    return SList(std::to_string(fabs(atof(arg[0].val().c_str()))));
}

SList greater_than (const SLists& argv) {
    for (auto vi = argv.begin(); vi != argv.end()-1; vi++) {
        if (atof((*(vi+1)).val().c_str()) >= atof((*vi).val().c_str()))
            return SList("#f");
    }
    return SList("#t");
}

SList less_than (const SLists& argv) {
    for (auto vi = argv.begin(); vi != argv.end()-1; vi++) {
        if (atof((*(vi+1)).val().c_str()) <= atof((*vi).val().c_str()))
            return SList("#f");
    }
    return SList("#t");
}

SList equal_num (const SLists& argv) {
    for (auto vi = argv.begin(); vi != argv.end()-1; vi++) {
        if (fabs(atof((*(vi+1)).val().c_str())-atof((*vi).val().c_str()))>0.00000001) {
            return SList("#f");
        }
    }
    return SList("#t");
}
