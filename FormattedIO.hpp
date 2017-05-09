//
//  STD_IN.hpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef STD_IN_hpp
#define STD_IN_hpp

#include <iostream>
#include <string>

class formattedIO {
public:
    static std::string readLine();
private:
    formattedIO ();
};

#endif /* STD_IN_hpp */
