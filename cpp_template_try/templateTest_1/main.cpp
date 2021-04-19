#include <iostream>
#include "template.hpp"

// int main()
// {
//     TestTemp<int> tempObj;
//     std::cout << "COUCOU" << std::endl;
//     tempObj.setValue(2);
//     int nValue = tempObj.getValue();
//     std::cout << "value [" << nValue << "]" << std::endl;
//     return 0;
// }

// ******************************************* //

#include <stdexcept>
using namespace std;

int main()
{
   try
   {
      Stack<int> intStack;       // stack of ints
      Stack<string> stringStack; // stack of strings

      // manipulate int stack
      intStack.push(7);
      cout << intStack.top() << endl;

      // manipulate string stack
      stringStack.push("hello");
      cout << stringStack.top() << std::endl;
      stringStack.pop();
      stringStack.pop();
   }
   catch (exception const &ex)
   {
      cerr << "Exception: " << ex.what() << endl;
      return -1;
   }
}