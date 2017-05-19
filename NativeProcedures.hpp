//
//  NativeProcedures.hpp
//  Scheme++
//
//  Created by Josh Sun on 2017-05-12.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef NativeProcedures_hpp
#define NativeProcedures_hpp

#include "SList.hpp"
#include "stdlib.h"
#include "math.h"

//primitives
SList add (const SLists& arg);
SList subtract (const SLists& arg);
SList multiply (const SLists& arg);
SList divide (const SLists& arg);
SList mod (const SLists& arg);
SList sqrt (const SLists& arg);
SList max (const SLists& argv);
SList min (const SLists& argv);

SList sin (const SLists& arg);
SList cos (const SLists& arg);
SList tan (const SLists& arg);
SList arcsin (const SLists& arg);
SList arccos (const SLists& arg);
SList arctan (const SLists& arg);

SList abs (const SLists& arg);

SList greater_than(const SLists& argv);
SList less_than (const SLists& argv);
SList equal_num (const SLists& argv);
SList append (const SLists& argv);
SList apply (const SLists& argv);
//special forms

#endif /* NativeProcedures_hpp */
