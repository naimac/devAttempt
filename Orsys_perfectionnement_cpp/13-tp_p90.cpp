class String
{
	// ...
public:
	String() {}
	~String() {}
	const char *afficher()
	{
		// ...
		return "test";
	}
};
class Object
{
};
// implémenter un smart pointeur sous forme de template
// surcharger l’opérateur -> et *. Créez la méthode get() qui
// retour le pointeur et la méthode reset().
int main()
{
	// Implémenter le template auto_var (sans copie), tel que
	auto_var<String> sp1(new String());
	sp1->afficher();
	(*sp1).afficher();
	auto_var<Object> sp2(new Object());
	return 0;
}