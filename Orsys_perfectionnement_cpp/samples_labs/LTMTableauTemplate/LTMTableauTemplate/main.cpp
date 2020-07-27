//
//  main.cpp
//  LTMTableauTemplate
#include <iostream>

using namespace std;

class String final { // non copiable
private:
    char * pBuffer;
    
public:
    String( const String& ) = delete; // c++11
    String& operator = ( const String& ) = delete;
    
    String( String&& ) = delete;
    String& operator = ( String&& ) = delete;
    
    String( char * c = NULL ) {
        Set( c );
    }
    
    ~String() {
        delete [] pBuffer;
        pBuffer = nullptr;
    }
    
    void Set( const char * c = NULL ) {
        if(c)
            delete  pBuffer;
        
        if( c != nullptr ) {
            pBuffer = new char[ strlen( c ) + 1 ];
            strcpy( pBuffer, c );
        }else {
            pBuffer = new char[ 1 ];
            *pBuffer = '\0';
        }
    }
    
    // ci-dessous pas trop conseillé
    operator const char * () const {
        return pBuffer;
    }
    
    const char * get() const {
        return pBuffer;
    }
};

template <typename Truc> class Tableau {
private:
    Truc * pointeurT = nullptr; // c++11
    const unsigned int nbr;
public:
    // ctor
    Tableau(unsigned int taille = 1) : nbr(taille) {
        // nbr=taille; // KO
        if( 0 != taille )
            pointeurT = new Truc[taille];
    }
    
    // dtor
    virtual ~Tableau() {
        delete [] pointeurT;
        pointeurT = nullptr;
    }
    
    Truc& operator [] ( unsigned int indice ) {
        return pointeurT[ indice ];
    }
    
    int nombre() const {
        return nbr;
    }
};

int main() {
    Tableau< int > TableauEntier( 10 );
    TableauEntier[0] = 0;
    TableauEntier[1] = 1;
    TableauEntier[2] = 2;
    TableauEntier[3] = 3;
    TableauEntier[4] = 4;
    TableauEntier[5] = 5;
    
    for( int t = 0; t < 6; t++ )
        cout << "TableauEntier[" << t << "] = " << TableauEntier[t] << endl;
    
    // String ...
    Tableau< String > TableauChaine( 100 );
    
    for( int t = 0; t < 6; t++ )
        TableauChaine[t].Set( "Toto" );
    
    for( int t = 0; t < 6; t++ )
        cout << "TableauChaine[" << t << "] = " << TableauChaine[t] << endl;
    
    std::cin.get();
    
    std::cout << TableauChaine[0].get();
    
    String s99( TableauChaine[0] );
    
    s99 = TableauChaine[0];
    
    
    return 0;
}
