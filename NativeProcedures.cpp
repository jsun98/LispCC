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
    return SList(dVal);
}

SList subtract (const SLists& argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal -= atof((*vi).val().c_str());
    return SList(dVal);
}

SList multiply (const SLists& argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal *= atof((*vi).val().c_str());
    return SList(dVal);
}

SList divide (const SLists& argv)  {
    double dVal = atof(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        dVal /= atof((*vi).val().c_str());
    return SList(dVal);
}

SList mod (const SLists& argv)  {
    int iVal = atoi(argv[0].val().c_str());
    for (auto vi = argv.begin()+1; vi != argv.end(); vi++)
        iVal %= atoi((*vi).val().c_str());
    return SList(iVal);
}

SList sqrt (const SLists& arg)  {
    return SList(sqrt(atof(arg[0].val().c_str())));
}

SList sin (const SLists& arg)  {
    return SList(sin(atof(arg[0].val().c_str())));
}

SList cos (const SLists& arg)  {
    return SList(cos(atof(arg[0].val().c_str())));
}

SList tan (const SLists& arg)  {
    return SList(tan(atof(arg[0].val().c_str())));
}

SList arcsin (const SLists& arg)  {
    return SList(asin(atof(arg[0].val().c_str())));
}

SList arccos (const SLists& arg)  {
    return SList(acos(atof(arg[0].val().c_str())));
}

SList arctan (const SLists& arg)  {
    return SList(atan(atof(arg[0].val().c_str())));
}

SList abs (const SLists& arg) {
    return SList(fabs(atof(arg[0].val().c_str())));
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

SList greater_equal (const SLists& argv) {
    for (auto vi = argv.begin(); vi != argv.end()-1; vi++) {
        if (atof((*(vi+1)).val().c_str()) > atof((*vi).val().c_str()))
            return SList("#f");
    }
    return SList("#t");
}

SList less_equal (const SLists& argv) {
    for (auto vi = argv.begin(); vi != argv.end()-1; vi++) {
        if (atof((*(vi+1)).val().c_str()) < atof((*vi).val().c_str()))
            return SList("#f");
    }
    return SList("#t");
}

SList append (const SLists& argv) {
    SList l;
    for (auto vi = argv.begin(); vi != argv.end(); vi++) {
        l.pushList(vi->getList());
        
    }
    return SList(l);
}

SList apply (const SLists& argv) {
    return argv[0].getProc()(argv[1].getList());
}

SList max (const SLists& argv) {
    double max = -std::numeric_limits<double>::infinity();
    for (auto vi = argv.begin(); vi != argv.end(); vi++) {
        if (atof(vi->val().c_str()) > max)
            max = atof(vi->val().c_str());
    }
    return max;
}

SList min (const SLists& argv) {
    double min = std::numeric_limits<double>::infinity();
    for (auto vi = argv.begin(); vi != argv.end(); vi++) {
        if (atof(vi->val().c_str()) < min)
            min = atof(vi->val().c_str());
    }
    return min;
}

SList eqv (const SLists& argv) {
    for (auto vi = argv.begin(); vi != argv.end()-1; vi++) {
        if (vi->getType() != (vi+1)->getType()) {
            return SList("#f");
        } else if (vi->getType() == SList::SYMBOL) {
            if (vi->val() == "#f" || vi->val() != (vi+1)->val())
                return SList("#f");
        } else if (vi->getType() == SList::NUMBER) {
            if (fabs(atof((*(vi+1)).val().c_str())-atof((*vi).val().c_str()))>0.00000001)
                return SList("#f");
        } else if (vi->getType() == SList::LAMBDA || vi->getType() == SList::PROC) {
            if (vi->getProc() != (vi+1)->getProc())
                return SList("#f");
        } else {
            return eqv(vi->getList());
        }
    }
    return SList("#t");
}


