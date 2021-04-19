#include "classValue.hpp"

using namespace space;

int main(void)
{
    ClassValue inst_classValue("tutu");
    // MyTemplate  inst_myTemplate<int>();

    std::cout << "instValue >> " << inst_classValue.getValue().c_str() << " <<" << std::endl;
    return 0;
}