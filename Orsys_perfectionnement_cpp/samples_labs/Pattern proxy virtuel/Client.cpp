//
#include <iostream>
#include <crtdbg.h>
#include "Factory.h"
#include "Object3D.h"

int main() {
	{
		Object3D * p = NULL;
		Factory f;

		p = f.Create();

		// use case 1 : use proxy object
		std::cout << "use case 1" << std::endl;
		std::cout << p->GetSize() << std::endl;

		// use case 2 : use heavy object
		std::cout << "use case 2" << std::endl;
		p->LoadGeometry();
		std::cout << p->GetSize() << std::endl;

		if( p != NULL ) {
			delete p;
			p = nullptr;
		}
	}
	//::_CrtDumpMemoryLeaks();

	return 0;
}
