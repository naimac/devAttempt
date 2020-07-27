boost::interprocess::interprocess_semaphore

class X
{
};

template <typename T>
class Singleton
{
private:
    // instance

public:
    X getInstance(void)
    {
    }
    //
};

int main()
{
    // Doit retourner une seule instance d'une classe donnée
    X *px = Singleton<X>::getInstance();
    X *px2 = Singleton<X>::getInstance();

    return 0;
}
