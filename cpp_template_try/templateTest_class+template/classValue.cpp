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
    return m_val;
}