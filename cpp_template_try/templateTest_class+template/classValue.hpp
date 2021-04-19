#include <iostream>

namespace space
{
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

    template <class T>
    class MyTemplate
    {
    private:
        ClassValue m_instClassValue;

    public:
        void printAnyValue(T anyVal);
    };

    template <class T>
    void MyTemplate<T>::printAnyValue(T anyVal)
    {
        m_instClassValue = ClassValue("TOTO");
        std::cout << "{" << m_instClassValue.getValue().c_str() << "} - [" << anyVal << "]" << std::endl;
    }
}