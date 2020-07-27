//
//  main.cpp

#include <iostream>

class String {
    //...
public:
    String( const char * = NULL ) {}
};

void swap( String& s1, String& s2 ) {
    String temp = s1;
    s1 = s2;
    s2 = temp;
}

template <typename T> void swap( T& s1, T& s2 ) {
    T temp = s1;
    s1 = s2;
    s2 = temp;
}

template<typename T = String, typename I = String> class Dictionnaire {
private:
    T * pKey;
    I * pValue;
public:
    // ...
    Dictionnaire( const T& cle, const I& valeur ) {
        //...
    }
};

template <typename T = String, typename I = int> void fonction( const T& rt, const I& ri ) {
    // ...
}

template <typename T> class Stack {
private:
    T * p;
public:
    Stack() : p(nullptr) {}
    ~Stack() {}
    void push( const T& t) {
        //...
    }
};

template <> class Stack<int> {
private:
    int T[256];
public:
    Stack() {}
    ~Stack() {}
    void push( int v ) {
        //...
    }
};






template <typename T> class Pile {
private:
    T * p;
public:
    Pile() : p(nullptr) {}
    ~Pile() {}
    void push( const T& t)
};

template <class T> void Pile<T>::push( const T& t ) {
    //...
}









// boost
template<class T> class scoped_ptr // noncopyable
{
private:
    T * px;
    
    scoped_ptr(scoped_ptr const &);
    scoped_ptr & operator=(scoped_ptr const &);
    
    typedef scoped_ptr<T> this_type;
    
    void operator==( scoped_ptr const& ) const;
    void operator!=( scoped_ptr const& ) const;
    
public:
    explicit scoped_ptr( T * p = 0 ): px( p ) { /* */ }
    
    explicit scoped_ptr( std::auto_ptr<T> p ) : px( p.release() ) { /* */ }
    
    ~scoped_ptr() { /* */ }
    
    void reset(T * p = 0) { /* */ }
    
    T & operator*() const { /* */ }
    T * operator->() const { return px; }
    
    T * get() { return px; }
    
    void swap(scoped_ptr & b)
    {
        T * tmp = b.px;
        b.px = px;
        px = tmp;
    }
};

int main(int argc, const char * argv[]) {
    
    fonction <> ( String(), 2 );
    fonction( String(), 3 );
    fonction <String, double> ( String(), 2.3 );
    fonction( String("test"), 4.5 );
    
    Dictionnaire<> dictionnaire1( "cle1", "valeur" );
    
    return 0;
}
