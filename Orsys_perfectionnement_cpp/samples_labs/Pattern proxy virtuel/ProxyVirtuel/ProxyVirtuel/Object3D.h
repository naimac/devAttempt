
//

#ifndef Object3D_h
#define Object3D_h

// C++ interface
class Object3D {
public:
	virtual void Draw() = 0;
	virtual void LoadGeometry() = 0;
	virtual int GetSize() = 0;
	virtual ~Object3D() {}
};

#endif