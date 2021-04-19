#include <iostream>

namespace space
{
    class Value
    {
    private:
        std::string m_val;
        /* data */
    public:
        Value();
        Value(const std::string &val);
        ~Value();
    std::string getValue();
    };

    template <class T>
    class MyTemplate
    {
    private:
        Value m_instClassValue;

    public:
        void printAnyValue(T anyVal);
    };

    template <class T>
    void MyTemplate<T>::printAnyValue(T anyVal)
    {
        m_instClassValue = Value("YOUPI");
        // std::string retValue = m_instClassValue.getValue();
        std::cout << "{" << m_instClassValue.getValue().c_str() << "} - [" << anyVal << "]" << std::endl;

        std::cout << "+++++++++ template [" << anyVal << "] +++++++++" << std::endl;
    }
}