#include "classValue.hpp"

using namespace space;

int main(void)
{
    Value  inst_classValue("main_tutu");
    // MyTemplate<std::string>::printAnyValue(std::string("main_pouet"));
    MyTemplate<std::string> myT;
    myT.printAnyValue(std::string("main_pouet"));

    std::cout << "main_instValue >> " << inst_classValue.getValue().c_str() << " <<" << std::endl;

    Value myDefaultVal;
    std::cout << "default val_original [" << myDefaultVal.getValue() << "]"<< std::endl;
    std::cout << "default val_overload [" << myDefaultVal.getValue("{pouet}") << "]"<< std::endl;
    return 0;
}