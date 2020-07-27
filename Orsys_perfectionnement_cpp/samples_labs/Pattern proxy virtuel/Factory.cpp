#include "Factory.h"
#include "Real3DObject.h"
#include "Proxy3DObject.h"

Factory::Factory() {}

Factory::~Factory() {
	/*if( 0 != _p ) {
		delete _p;
		_p = 0;
	}*/
}

Object3D * Factory::Create() {
	//_p = new Real3DObject();
	return new Proxy3DObject();
}
