// p.99
class String
{
private:
    char _tabPtr[256];

public:
    explicit String(const char *c = nullptr) {}
    ~String() {}
    String &operator+=(const String &s)
    {
        strncat(_tabPtr, s._tabPtr, 255);
        return *this;
    }
};