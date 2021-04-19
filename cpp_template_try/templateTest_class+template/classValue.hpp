#include <iostream>

namespace space
{
    class Value
    {
    private:
        std::string m_val;
        /* data */
    public:
        Value(const std::string &val);
        ~Value();
        std::string getValue() const;
    };

    template <class T>
    class MyTemplate
    {
    private:
        static Value m_instClassValue;

    public:
        static void printAnyValue(T anyVal);
    };

    template <class T>
    void MyTemplate<T>::printAnyValue(T anyVal)
    {
        // m_instClassValue = ClassValue("template_TOTO");
        // std::cout << "{" << m_instClassValue.getValue().c_str() << "} - [" << anyVal << "]" << std::endl;
        std::cout << "+++++++++ template [" << anyVal << "] +++++++++" << std::endl;
    }
}