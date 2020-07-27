//

#include <iostream>

int main(int argc, const char * argv[]) {

    int b = 3;
    int& rb = b;
    
    int &&a = std::move(rb);
    b = 4;
    
    std::cout << "a = "<< a << std::endl;
    std::cout << "rb = "<< rb << std::endl;
    
    return 0;
}

