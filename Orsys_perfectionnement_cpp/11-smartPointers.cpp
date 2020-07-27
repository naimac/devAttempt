class X
{
public:
	void method() {}
};
template <class truc>
class auto_var
{
private:
	truc *_p;

public:
	// pas de copie autorisée
	auto_var(const auto_var &) = delete;
	auto_var &operator=(const auto_var &) = delete;
	auto_var(truc *pp) : _p(pp) {} // match avec la ligne 40
	~auto_var()
	{
		delete _p;
		_p = nullptr;
	}
	truc *operator->() const
	{
		return _p;
	}
};

// on peut mettre un smart pointer comme membre de classe
int main()
{
	//
	X *p = new X();
	// ...
	delete p;
	p = nullptr;
	// allocation avec un smart pointer
	auto_var<X> sp(new X());
	sp->method();
	return 0;
	= delete;
	auto_var(truc * pp) : _p(pp) {}
	~auto_var()
	{
		delete _p;
		_p = nullptr;
	}

	// operateur de dereferenciation
	truc *operator->() const // permet de flecher le smart pointer
	{
		return _p;
	}

	// AUTRE EXEMPLE
	X *px = new X();
	std::unique_ptr<X> uniq3 (px);
	std::unique_ptr<X> uniq4 (px); // pourri

	// std::make_unique permet de creer des instances et cacher le new
	// make_unique pour rendre un shared_ptr unique

	return 0;
};
