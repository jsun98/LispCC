//
//  NativeProcedures.cpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-12.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#include "NativeProcedures.hpp"

SList add (SLists argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal += atof((*vi).val().c_str());
    return SList(std::to_string(dVal));
}

SList subtract (SLists argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal -= atof((*vi).val().c_str());
    return SList(std::to_string(dVal));
}

SList multiply (SLists argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal *= atof((*vi).val().c_str());
    return SList(std::to_string(dVal));
}

SList divide (SLists argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal /= atof((*vi).val().c_str());
    return SList(std::to_string(dVal));
}

SList mod (SLists argv)  {
    int iVal = atoi(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        iVal %= atoi((*vi).val().c_str());
    return SList(std::to_string(iVal));
}

SList sqrt (SLists arg)  {
    return SList(std::to_string(sqrt(atof(arg[0].val().c_str()))));
}

SList sin (SLists arg)  {
    return SList(std::to_string(sin(atof(arg[0].val().c_str()))));
}

SList cos (SLists arg)  {
    return SList(std::to_string(cos(atof(arg[0].val().c_str()))));
}

SList tan (SLists arg)  {
    return SList(std::to_string(tan(atof(arg[0].val().c_str()))));
}

SList arcsin (SLists arg)  {
    return SList(std::to_string(asin(atof(arg[0].val().c_str()))));
}

SList arccos (SLists arg)  {
    return SList(std::to_string(acos(atof(arg[0].val().c_str()))));
}

SList arctan (SLists arg)  {
    return SList(std::to_string(atan(atof(arg[0].val().c_str()))));
}

SList abs (SLists arg) {
    return SList(std::to_string(fabs(atof(arg[0].val().c_str()))));
}
