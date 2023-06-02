#include "iostream"
//#include <ostream>

using namespace std;

class A
{
public:
    A(double val, ostream& out)
        : m_val{val}
    {
        m_initCount++;
        out << m_initCount << ". object: ";
    }

    operator double()
    {
        return m_val;
    }

    void static statistics(ostream& out)
    {
        out << "A total of " << m_initCount << " objects was created." << endl;
    }

private:
    double m_val;
    static int m_initCount;
};

int A::m_initCount = 0;

int main()
{
    A a(12.34, cout);       cout << a << endl;
    A b(-34.56, cout);      cout << b << endl;
    A c(99.88, cout);       cout << c << endl;
    A::statistics(cout);
    return 0;
}