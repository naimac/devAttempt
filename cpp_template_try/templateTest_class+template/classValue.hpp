#include <iostream>

class ClassValue
{
private:
    std::string m_val;
    /* data */
public:
    ClassValue(const std::string &val);
    ~ClassValue();
    std::string getValue() const;
};