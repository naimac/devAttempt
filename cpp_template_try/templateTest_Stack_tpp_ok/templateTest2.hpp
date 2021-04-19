
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

namespace space
{
   template <class T>
   class Stack
   {
   private:
      vector<T> elems; // elements

   public:
      void push(T const &); // push element
      void pop();           // pop element
      T top() const;        // return top element

      bool empty() const
      { // return true if empty.
         return elems.empty();
      }
   };
} // namespace space
#include "templateTest2.tpp"