//
//  main.cpp
//  LTMflyweight
#include <iostream>
#include <map>

class IconObject {
public:
    virtual ~IconObject() {}
    virtual const unsigned char * getIcon() = 0;
};

// mouche
class IconFlyWeight : public IconObject {
private:
    unsigned char tab[65536*16]; // icon size simulation
public:
    IconFlyWeight() = default;
    virtual ~IconFlyWeight() {}
    virtual const unsigned char * getIcon() override {
        return tab;
    }
};

/////
class Factory final {
private:
    static std::map<const char *, IconObject *> dictionnaire;
public:
    static IconObject * create( const char * p ) {
        IconObject * o = dictionnaire[p];
        if(o)
            return o;
        else {
            IconObject * po = new IconFlyWeight();
            dictionnaire[p] = po;
            return po;
        }
    }

    Factory() = delete;
    
    static void reset() {
        for( auto it = dictionnaire.begin(); it != dictionnaire.end(); it++ ) {
            delete it->second;
        }
        dictionnaire.clear();
    }
};

std::map<const char *, IconObject *> Factory::dictionnaire;

void clearAfterMain() {
    Factory::reset();
}

int main() {
    atexit(clearAfterMain); // clear after main()
    
    IconObject * pi1 = Factory::create("word");
    IconObject * pi2 = Factory::create("cpp");
    IconObject * pi3 = Factory::create("word");
    
    const unsigned char * pIcon1 = pi1->getIcon();
    const unsigned char * pIcon2 = pi2->getIcon();
    const unsigned char * pIcon3 = pi3->getIcon();
    
    std::cout << (void*)pIcon1 << std::endl;
    std::cout << (void*)pIcon2 << std::endl;
    std::cout << (void*)pIcon3 << std::endl;

    return 0;
}
