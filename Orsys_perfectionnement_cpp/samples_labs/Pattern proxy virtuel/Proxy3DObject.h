
//

#ifndef proxy3Dobject_h
#define proxy3Dobject_h

#include "Object3D.h"
#include "Real3DObject.h"

class Proxy3DObject : public Object3D { // non copyable
private:
	Real3DObject * _p;
public:
	Proxy3DObject();
	virtual ~Proxy3DObject();
	void Draw();
	void LoadGeometry();
	int GetSize();
private:
	Proxy3DObject( const Proxy3DObject& );
	Proxy3DObject& operator = ( const Proxy3DObject& );
};

#endif