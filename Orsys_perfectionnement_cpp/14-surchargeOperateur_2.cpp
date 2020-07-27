#include <iostream>

class String
{
private:
	char *_ptr;

public:
	String() : _ptr(nullptr) {}
	~String() {}

	// opérateur de conversion (trasntipage)
	operator const char *() const
	{
		return _ptr;
	}

	operator const char *() const{
		return strlen(_ptr);
	}

	const char *get() const 
	{
		return _ptr;
	}
};

int main()
{
	String s1;

	// std::cout << s1.operator const char *(); // c'est lui le retour IL RETOURNE RIEN
	std:cout << s2 // marche pas
	std::cout << s2.get();

	return 0;
}