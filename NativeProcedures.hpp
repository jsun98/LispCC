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


SList add (SLists argv);
SList subtract (SLists argv);
SList multiply (SLists argv);
SList divide (SLists argv);
SList mod (SLists argv);
SList sqrt (SLists arg);

SList sin (SLists arg);
SList cos (SLists arg);
SList tan (SLists arg);
SList arcsin (SLists arg);
SList arccos (SLists arg);
SList arctan (SLists arg);

SList abs (SLists arg);


#endif /* NativeProcedures_hpp */
