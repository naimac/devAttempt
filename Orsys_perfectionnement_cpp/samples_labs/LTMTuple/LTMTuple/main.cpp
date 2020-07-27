//
//  main.cpp
//  LTMTuple
//

#include <iostream>
#include <tuple>

using namespace std;

std::tuple<int,int> fonction() {
    //...
    auto ret = std::make_tuple(1, 3);
    return ret;
}

int main() {

    std::tuple<int, int> tuple1( 1, 2 );
    
    std::tuple<int, string> erreur( 404, string("not found") );
    
    tuple1 = fonction();
    
    cout << get<0>(tuple1) << " , " << get<1>(tuple1) << endl;;
    
    return 0;
}
