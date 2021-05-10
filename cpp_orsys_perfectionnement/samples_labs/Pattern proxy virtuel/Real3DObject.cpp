#include "Real3DObject.h"

// construct a true real 3D object (heavy state)
Real3DObject::Real3DObject() : _pgeometry(0) {
}

Real3DObject::~Real3DObject() {
	if( _pgeometry ) {
		delete [] _pgeometry;
		_pgeometry = 0;
	}
}

void Real3DObject::Draw() {
	if( _pgeometry ) {
		// .. draw here
	}
}

void Real3DObject::LoadGeometry() {
	if( _pgeometry == 0 ){
		// the first time ...
		_pgeometry = new char[65536];
		// init geometry ...
	}
	// ...
}

int Real3DObject::GetSize() {
	if( _pgeometry == 0 ) 
		return sizeof(*this);
	else {
		return sizeof(*this) + 65536;
	}
}
