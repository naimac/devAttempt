#include "Proxy3DObject.h"

Proxy3DObject::Proxy3DObject() : _p(0) {
	_p = new Real3DObject();
}

Proxy3DObject::~Proxy3DObject() {
	if( 0 != _p ) {
		delete _p;
		_p = 0;
	}
}

void Proxy3DObject::Draw() {
	_p->Draw();
}

void Proxy3DObject::LoadGeometry() {
	_p->LoadGeometry();
}

int Proxy3DObject::GetSize() {
	return _p->GetSize();
}
