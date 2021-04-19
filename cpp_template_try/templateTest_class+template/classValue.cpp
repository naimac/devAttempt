#include "classValue.hpp"

using namespace space;

Value::Value(const std::string &val) : m_val {val}
{
}

Value::~Value()
{
}

std::string Value::getValue() const
{
    return this->m_val;
}