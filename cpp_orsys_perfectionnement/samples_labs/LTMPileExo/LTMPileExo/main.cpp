//
//  main.cpp
//  LTMPileExo
//
#include <iostream>
//#include <crtdbg.h>

// classe pile d' Int, PILE LIFO
class PileInt {
    int * TabInt;           // Pointeur sur la pile
    short NbrInt;           // Nbr d'éléments dans la pile
public:
    PileInt() : NbrInt(0) {}
    ~PileInt() {}
    void Push( int );       // On pousse sur la pile
    int Pop();              // On retire un élément de la pile
    short GetNbrFigures();  // On obtient le nbr d'éléments de la pile
    void PrintPile();       // On imprime le contenu de la pile
};

void PileInt::Push( int i ) {
    if( TabInt == NULL )
        TabInt = new int[1];
    else {
        // realloc
        int * Temp = new int[ NbrInt + 1 ];
        memcpy( Temp, TabInt, NbrInt * sizeof( int ) );
        
        TabInt = Temp;
    }
    TabInt[NbrInt++] = i;
}

int PileInt::Pop() {
    if( NbrInt > 0 ) {
        int Ret = TabInt[NbrInt--];
        return Ret; }
    else
        return -9999;
}

short PileInt::GetNbrFigures() {
    return NbrInt;
}

void PileInt::PrintPile() {
    for( int t = 0; t <= NbrInt; t++ )
        std::cout << "Element [" << t << "] -> " << TabInt[t] << std::endl;
}

int main() {
    {
        PileInt Pile1;
        Pile1.Push( 1 );
        Pile1.Push( 2 );
        Pile1.Push( 3 );
        Pile1.Push( 4 );
        Pile1.Push( 5 );
        Pile1.PrintPile();
        std::cout << Pile1.Pop() << std::endl;
        std::cout << Pile1.Pop() << std::endl;
        std::cout << Pile1.Pop() << std::endl;
        std::cout << Pile1.Pop() << std::endl;
        std::cout << Pile1.Pop() << std::endl;
        std::cout << Pile1.Pop() << std::endl;
        Pile1.PrintPile();
        Pile1.Push( 10 );
        Pile1.Push( 20 );
        Pile1.Push( 30 );
        Pile1.Push( 40 );
        Pile1.Push( 50 );
        Pile1.Pop();
        Pile1.PrintPile();
    }
    //::crtDumpMemoryLeaks();
    
    int t=0;
    std::cin >> t;
    
    return 0;
}
