#include <iostream>

template <typename K = String, typename V = String>
class Dictionnaire
{
private:
	K *pKey;
	V *pValue;
public: // ...
};

int main()
{
	Dictionnaire<> dict1;
	Dictionnaire<String, int> dict2;
	
	return 0;
}