#include <iostream>
#include <thread>

void maTache()
{
}

int main()
{
	std::thread threads[5];

	for (int i = 0; i < 5; ++i)
		threads[i] = std::thread(maTache); //rvalue a droite
	return 0;
}