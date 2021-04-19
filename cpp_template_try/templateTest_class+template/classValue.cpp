#include "classValue.hpp"

using namespace space;

ClassValue::ClassValue(const std::string &val) : m_val {val}
{
}

ClassValue::~ClassValue()
{
}

std::string ClassValue::getValue() const
{
    return this->m_val;
}