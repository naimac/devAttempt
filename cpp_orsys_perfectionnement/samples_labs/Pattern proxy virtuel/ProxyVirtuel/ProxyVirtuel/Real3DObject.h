
//
#ifndef real3DObject_h
#define real3DObject_h

#include "Object3D.h"

class Real3DObject : public Object3D { // non copyable
public:
	Real3DObject();
	~Real3DObject();
	void Draw();
	void LoadGeometry();
	int GetSize();
private:
	char * _pgeometry; // big tab for geometry
private:
	Real3DObject( const Real3DObject& );
	Real3DObject& operator = ( const Real3DObject& );
};

#endif