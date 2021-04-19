namespace space
{
   template <class T>
   void Stack<T>::push(T const &elem)
   {
      // append copy of passed element
      elems.push_back(elem);
   }

   template <class T>
   void Stack<T>::pop()
   {
      if (elems.empty())
      {
         throw out_of_range("Stack<>::pop(): empty stack");
      }

      // remove last element
      elems.pop_back();
   }

   template <class T>
   T Stack<T>::top() const
   {
      if (elems.empty())
      {
         throw out_of_range("Stack<>::top(): empty stack");
      }

      // return copy of last element
      return elems.back();
   }
}