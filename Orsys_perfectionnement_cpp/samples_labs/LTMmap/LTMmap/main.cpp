//
//  main.cpp
//  LTMmap
//
//  Created by bleclercq on 27/02/2015.
//  Copyright (c) 2015 LTM. All rights reserved.
//

#include <iostream>
#include <map>

class X {
    char b[256];
public:
    X() { strcpy(b, "test"); }
    operator const char * () const {
        return b;
    }
};

int main(int argc, const char * argv[]) {
    
    X x1, x2, x3;
    
    std::map<std::string, X> maListe;
    
    maListe["key1"] = x1;
    maListe["key2"] = x2;
    maListe["key3"] = x3;
    
    for( std::map<std::string, X>::iterator ii=maListe.begin(); ii!=maListe.end(); ++ii) {
        std::cout << (*ii).first << ": " << (*ii).second << std::endl;
    }

    
    return 0;
}
