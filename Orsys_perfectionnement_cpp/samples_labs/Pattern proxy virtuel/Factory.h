//

#ifndef factory_h
#define factory_h

class Object3D;
class Real3DObject;

class Factory { // non copyable
public:
	Factory();
	virtual ~Factory();
	Object3D * Create();
private:
	//Real3DObject * _p;
private:
	Factory( const Factory& );
	Factory& operator = ( const Factory& );
};

#endif