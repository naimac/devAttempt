//
//  main.cpp
//  TdOperateur
#include <iostream>

// 1.
class String {
private:
    char * _ptr = nullptr;
public:
    // ctor
    String( const char * p = nullptr ) {
        if( p != nullptr ) {
            _ptr = new char[strlen(p)+1];
            strcpy(_ptr, p);
        }else
            _ptr = nullptr;
    }
    
    // copy ctor
    String( const String& cs ) {
        if( cs._ptr != nullptr ) {
            _ptr = new char[strlen(cs._ptr)+1];
            strcpy(_ptr, cs._ptr);
        }else
            _ptr = nullptr;
    }
    
    // Affectation s1 = s2 = s3;
    String& operator = (const String& cs) {
        if( this != &cs && cs._ptr != nullptr ) {
            if(_ptr != nullptr)
                delete [] _ptr;
            
            _ptr = new char[strlen(cs._ptr)+1];
            strcpy(_ptr, cs._ptr);
        }
        return *this; // retourne l'objet courant
    }
    
    
    // 2.
    operator const char *() const {
        return _ptr;
    }
    
    // 3. s1 += s2;
    String& operator +=( const String& cs ) {
        
        if(cs._ptr == nullptr)
            return *this;
        
        if( _ptr == nullptr ) {
            this->_ptr = new char[strlen(cs._ptr)+1];
            strcpy(_ptr, cs._ptr);
        }else {
            char * temp = new char[strlen(_ptr)+strlen(cs._ptr)+1];
            strcpy( temp, _ptr );
            strcat( temp, cs._ptr );
            delete [] _ptr;
            _ptr = temp;
        }
        
        return *this;
    }
    
    const char * get() const {
        return _ptr;
    }
    
    
    
    
    
    // 4. s1 = (s2 + s3);
    String operator + (const String& cs ) const {
        String temp(*this);
        temp += cs;
        return temp;
    }
    
    
    
    
    
    
    
    
    
    bool operator ==( const String& cs ) const {
        return !strcmp( _ptr, cs._ptr );
    }
    
    bool operator !=( const String& cs ) const {
        return strcmp( _ptr, cs._ptr );
    }
    
    
    
    
    
    
    
    
    
    
    
    ~String() {
        if(_ptr) {
            delete [] _ptr;
            _ptr = nullptr;
        }
    }
};

int main() {
    String s1("test");
    String s3;
    s3 += s1;
    
    String s4("test");
    s4 += s1;
    
    String s5("test");
    String s10;
    s10 = s4 + s5 + s1;
    
    if( s1 == s3 ) {
        
    }else {
        
    }
    
    std::cout << s1.get() << std::endl;
    
    return 0;
}
