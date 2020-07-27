#include <iostream>
template struct static_constructor
{
	struct constructor
	{
		constructor() { ctor(); }
	};
	static constructor c;
};

template <typename static_constructor::constructor static_constructor::c>;

int main()
{
	return 0;
}