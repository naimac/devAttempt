//
//  main.cpp
//  LTMflyweight
#include <iostream>
#include <map>

class IconObject {
public:
    //...
};

class IconFlyWeight : public IconObject {
public:
    unsigned char tab[65536*16]; // icon size simulation
};

class Factory final {
private:
    std::map<const char *, IconObject *> dictionnaire;
public:
    IconObject* create( const char * p ) {
        IconObject * o = dictionnaire[p];
        if(o)
            return o;
        else {
            IconObject * po = new IconFlyWeight();
            dictionnaire[p] = po;
            return po;
        }
    }

    Factory() {}
    
    ~Factory() {
        for( auto it = dictionnaire.begin(); it != dictionnaire.end(); it++ ) {
            delete it->second;
        }
        dictionnaire.clear();
    }
};

int main() {
    Factory f;
    IconObject * pi1 = f.create("word");
    IconObject * pi2 = f.create("cpp");
    IconObject * pi3 = f.create("word");
    
    return 0;
}
