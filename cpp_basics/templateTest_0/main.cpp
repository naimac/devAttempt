// ***************************************** decltype *************************************************** //

#include <iostream>
#include <typeinfo>
#include <type_traits>

// \tparam T Either \c bool, \c int, \c unsigned, \c int64_t, \c uint64_t, \c double, \c float, \c const \c char*, \c std::basic_string<Ch>

template < class V >
void    print(V val)
{
    if (std::is_same<V, int>())
    {
        std::cout << "XXXXX int XXXX" << std::endl;
    }
    else if (std::is_same<V, int32_t>())
    {
        std::cout << "XXXXX int32_t XXXX" << std::endl;
    }
    else if (std::is_same<V, uint32_t>())
    {
        std::cout << "XXXXX uint32_t XXXX" << std::endl;
    }
    else if (std::is_same<V, int64_t>())
    {
        std::cout << "XXXXX int64_t XXXX" << std::endl;
    }
    else if (std::is_same<V, uint64_t>())
    {
        std::cout << "XXXXX uint64_t XXXX" << std::endl;
    }
    else if (std::is_same<V, std::string>())
    {
        std::cout << "XXXXX std::string XXXX" << std::endl;
    }
    else if (std::is_same<V, double>())
    {
        std::cout << "XXXXX double XXXX" << std::endl;
    }
    else if (std::is_same<V, float>())
    {
        std::cout << "XXXXX float XXXX" << std::endl;
    }
    else if (std::is_same<V, char *>())
    {
        std::cout << "XXXXX char * XXXX" << std::endl;
    }
    std::cout << ">> print [" << val << "] dataType [" << typeid(val).name() << "]" << std::endl;
    std::cout << std::endl; 
}

int main(void)
{
	int             val_int = 12;
    int32_t         val_int32_t = 32;
	uint32_t	    val_uint32_t = 23;
	int64_t		    val_int64_t = 64;
	uint64_t	    val_uint64_t = 46;
	std::string     val_string("ABCD");
	double          val_double = 3.3;
	float           val_float = 3.3f;
    char            val_charArray[] = "pouet";
    // auto            val_auto = 2.4f;

    std::cout<< "=> main [" << val_int << "] dataType int [" << typeid(val_int).name() << "]" << std::endl;
    print<int>(val_int);

    std::cout<< "=> main [" << val_int32_t << "] dataType int32 [" << typeid(val_int32_t).name() << "]" << std::endl;
    print<int32_t>(val_int32_t);

    std::cout<< "=> main [" << val_uint32_t << "] dataType uint32 [" << typeid(val_uint32_t).name() << "]" << std::endl;
    print<uint32_t>(val_uint32_t);

    std::cout<< "=> main [" << val_int64_t << "] dataType int64 [" << typeid(val_int64_t).name() << "]" << std::endl;
    print<int64_t>(val_int64_t);

    std::cout<< "=> main [" << val_uint64_t << "] dataType uint64 [" << typeid(val_uint64_t).name() << "]" << std::endl;
    print<uint64_t>(val_uint64_t);

    std::cout<< "=> main [" << val_string << "] dataType std::string [" << typeid(val_string).name() << "]" << std::endl;
    print<std::string>(val_string);

    std::cout<< "=> main [" << val_double << "] dataType double [" << typeid(val_double).name() << "]" << std::endl;
    print<double>(val_double);

    std::cout<< "=> main [" << val_float << "] dataType float [" << typeid(val_float).name() << "]" << std::endl;
    print<double>(val_float);

    std::cout<< "=> main [" << val_charArray << "] dataType char * [" << typeid(val_charArray).name() << "]" << std::endl;
    print<char*>(val_charArray);

    // // std::cout<< "main [" << val_auto << "] dataType [" << typeid(val_auto).name() << "]" << std::endl;
    // // print<auto>(val_auto);

    return 0;
}