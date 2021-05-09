//
//  main.cpp
//  LTMWeak_ptr

#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void foo() {
    if (auto spt = gw.lock()) {
        std::cout << *spt << "\n";
    }else {
        std::cout << "gw est expiré" << std::endl;
    }
}

int main() {
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
        foo();
    }
    foo();
}
