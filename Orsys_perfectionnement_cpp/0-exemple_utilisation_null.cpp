#include

class Y;

class X
{
private:
	Y *_px;

public:
	X() : _px(new Y()) ~X()
	{
		delete _px;
		_px = NULL;
	}
};

int main()
{
	const int i = 0;
	X *px = new X();
	X *px2 = px;
	//...
	delete px;
	delete px2;
	px = NULL;
}