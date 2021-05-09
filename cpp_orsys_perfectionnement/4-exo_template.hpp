#ifndef EXO_TEMPLATE_HPP
#define EXO_TEMPLATE_HPP

template <typename T> class Tableau {
	private:
	T *type = nullptr; // c++11
	int nb;

	public:
	Tableau (int size) : nb(size){
		type = new T[size];
	}

	~Tableau (){
		delete [] type;
		type = nullptr;
	}

	T &operator[] (int size)
	{
		return type[ size ];
	}
};

#endif