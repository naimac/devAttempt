#include "classValue.hpp"

int main(void)
{
    ClassValue inst_classValue("tutu");

    std::cout << "instValue [" << inst_classValue.getValue().c_str() << "]" << std::endl;
    return 0;
}