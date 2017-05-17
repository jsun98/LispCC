//
//  STD_IN.hpp
//  Scheme_Interpreter
//
//  Created by Josh Sun on 2017-05-08.
//  Copyright © 2017 Josh Sun. All rights reserved.
//

#ifndef FormattedIO_hpp
#define FormattedIO_hpp

#include <iostream>
#include <string>
#include <fstream>

class FormattedIO {
public:
    static std::string readLine();
    static std::string readLicense();
    virtual ~FormattedIO();
private:
    FormattedIO ();
};

#endif /* STD_IN_hpp */
