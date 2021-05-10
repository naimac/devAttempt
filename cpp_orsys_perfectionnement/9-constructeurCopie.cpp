class Segment
{
private:
	Point _p1, _p2;

public:
	// Le mot clé default permet la copie
	explicit Segment(const Segment &s) = default; // il va le creer lui meme
	// default permet le mecanisme
};

int main()
{
	//...
	Segment seg1(p1, p2);
	Segment seg2(seg1);
	seg2 = seg1; // même problème avec l’opérateur = return 0;
}