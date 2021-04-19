// TestTemp.cpp
#include "test_template.hpp"
#include <iostream>

template <typename T>
TestTemp<T>::TestTemp()
{
}
 
template <typename T>
void TestTemp<T>::setValue( T obj_i )
{
    m_obj = obj_i;
}
 
template <typename T>
T TestTemp<T>::getValue()
{
    return m_obj;
}

template <typename T>
void    TestTemp<T>::pouet()
{
    std::cout << "pouet" << std::endl;  
}

// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
void TemporaryFunction ()
{
    TestTemp<int> TempObj;
}

int main()
{
    TestTemp<int> tempObj;
    std::cout << "COUCOU" << std::endl;
    tempObj.setValue(2);
    int nValue = tempObj.getValue();
    std::cout << "value [" << nValue << "]" << std::endl;
    return 0;
}