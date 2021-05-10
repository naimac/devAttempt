//
//  main.cpp
//  LTMSTL
//

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <deque>
#include <list>

int main()
{
    // std::array
    std::array<int, 3> a1{ {4, 2, 3} }; // double-braces required in C++11 (not in C++14)
    std::array<int, 3> a2 = {1, 2, 3};  // never required after =
    std::array<std::string, 2> a3 = { std::string("a"), "b" };
    
    // container operations are supported
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(),
                      std::ostream_iterator<int>(std::cout, " "));
    
    std::cout << '\n';
    
    // ranged for loop is supported
    for(const auto& s: a3)
        std::cout << s << ' ';
    
    // std::vector
    std::vector<int> v = {6, 32, 16, 9};
    
    // Add two more integers to vector
    v.push_back(25);
    v.push_back(13);
    
    // Iterate and print values of vector
    for(int n : v) {
        std::cout << std::endl << n << '\n';
    }
    
    // std::dequeue
    std::deque<int> d = {7, 5, 16, 8};
    
    // Add an integer to the beginning and end of the deque
    d.push_front(13);
    d.push_back(25);
    
    // Iterate and print values of deque
    for(int n : d) {
        std::cout << n << '\n';
    }
    
    // std::list : std::list is a container that supports constant time insertion and removal of elements from anywhere in the container
    std::list<int> l = { 7, 5, 16, 8 };
    
    // Add an integer to the front of the list
    l.push_front(25);
    // Add an integer to the back of the list
    l.push_back(13);
    
    // Insert an integer before 16 by searching
    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end()) {
        l.insert(it, 42);
    }
    
    // Iterate and print values of the list
    for (int n : l) {
        std::cout << n << '\n';
    }
}
