#include "classValue.hpp"

using namespace space;

int main(void)
{
    Value  inst_classValue("main_tutu");
    // MyTemplate<std::string>::printAnyValue(std::string("main_pouet"));
    MyTemplate<std::string> myT;
    myT.printAnyValue(std::string("main_pouet"));

    Value myDefaultVal;

    std::cout << "main_instValue >> " << inst_classValue.getValue().c_str() << " <<" << std::endl;
    std::cout << "default val [" << myDefaultVal.getValue() << "]"<< std::endl;
    return 0;
}