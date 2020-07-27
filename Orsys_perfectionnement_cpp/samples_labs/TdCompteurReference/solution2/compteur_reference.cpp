// solution avec compteur de référence dans le cercle
#include <iostream>
using namespace std;

class BaseUnknown {
	int cpt;
protected: // classe abstraite
	BaseUnknown() : cpt(0) {
		cout << "Constructeur de BaseUnknown " << this << endl;
	}
	virtual ~BaseUnknown() {
		cout << "Destructeur de BaseUnknown " << this << endl;
	}
public:
	void AddRef() { // pas thread safe !
		++cpt;
		cout << this << " AddRef -> cpt = " << cpt << endl;
	}
	long Release() {
		--cpt;
		cout << this << " Release -> cpt = " << cpt << endl;
		
        return cpt;
	}
	long use_count() {
		return cpt;
	}
};

class Figure : public BaseUnknown {
public: // classe abstraite
	Figure() {
		cout << "Constructeur de Figure " << this << endl;	
	}
	virtual ~Figure() {
		cout << "Destructeur de Figure " << this << endl;	
	}
	virtual void Draw() = 0;
};

class Circle : public Figure {
public:
	Circle() {}
	~Circle() {}
	virtual void Draw() {}
};

template <class truc> class auto_var {
private:
	truc * p;
private:
	truc& operator = ( const truc& );
public:
	auto_var( truc * pt = NULL ) : p(pt) {
		if( pt != NULL ) {
			pt->AddRef();
		}else {}
	}
	auto_var( const auto_var& ra ) : p(NULL) {
		if( ra.p != NULL ) {
			p = ra.p;
			p->AddRef();
		}
	}
	~auto_var() {
		if( p != NULL ) {
			if( p->use_count() == 1 ) {
				cout << "Destruction de " << p << " par le smartpointer" << endl;
				delete p;
				p = NULL;
			}
			else {
				p->Release();
			}
		}
	}
	truc * operator -> () const;
};

template <class truc> truc * auto_var<truc>::operator -> () const {
		return p;
}

int main() {

	Circle * pc = new Circle;
    pc->AddRef();
	
    auto_var <Circle> sp1 = pc;

	auto_var <Circle> sp2 = pc;
	auto_var <Circle> sp3 = sp2;	
	auto_var <Circle> sp4 = sp2;	

	auto_var <Circle> sp5( new Circle );
	auto_var <Circle> sp6( sp5 );
	sp6->Draw();
    
    std::cout << pc->use_count();
    pc->Release();
    // destruction à prévoir si cpt==0

	return 1;
}
