//
//  TemplateSingleton.cpp
//  LTMSingleton
#include <mutex>

template <typename T> class Singleton {
private:
    static T * _instance; // avant C++17
    //static inline T* _instance = nullptr; // C++ 17
    static std::mutex m;

public:
    static T* getInstance() {
        static Liberation lib; // Libération du singleton
        
        m.lock();
        if (!_instance) {
            _instance = new T();
        }
        m.unlock();
        
        return _instance;
    }
    
    // C++11, copie interdite
    Singleton(const Singleton&) = delete;
    Singleton& operator= (const Singleton&) = delete;
    
protected:
    Singleton() {};
    virtual ~Singleton() { }
private:
    struct Liberation {
        ~Liberation() {
            delete _instance;
            _instance = nullptr;
        }
    };
};

// initialisation de static dans un tamplate
template <typename T> T * Singleton<T>::_instance = nullptr; // !!!!!!!

template <typename T> std::mutex Singleton<T>::m;

class X {};

int main() {
    X * px = Singleton<X>::getInstance();
    X * px2 = Singleton<X>::getInstance();
    
    return 0;
}


























