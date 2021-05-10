#include "classValue.hpp"

using namespace space;

Value::Value() : m_val(std::string("KASSOS"))
{
}

Value::Value(const std::string &val) : m_val(val)
{
}

Value::~Value()
{
}

std::string Value::getValue()
{
    MyTemplate<std::string> myT;
    myT.printAnyValue(std::string("main_pouet"));
    
    return m_val;
}

std::string Value::getValue(const std::string &s)
{
    std::string str = s + " [X] " + m_val;
    return str;
}