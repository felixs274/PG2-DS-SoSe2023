#include "iostream"
//#include <ostream>

using namespace std;

class A
{
    public:
    A(double arg1, ostream& out)
    {
        m_initCount++;
        out << m_initCount << ". object: " << arg1 << endl;
    }

    void static statistics(ostream& out)
    {
        out << "A total of " << m_initCount << " objects was created." << endl;
    }
    private:
    static int m_initCount;
};
int A::m_initCount = 0;

int main()
{
    A a(12.34, cout);
    A b(-34.56, cout);
    A c(99.88, cout);
    A::statistics(cout);
    return 0;
}