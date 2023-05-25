#include "midpoint.h"
#include <array>

using std::cout;
using std::endl;
using std::array;


int main() {

    typedef Point P;

    array < array < Point, 4 > , 10 > arr = {
        {
            {
                {
                    P(23.5, 10.1, 7.7), P(-7.8, -5.2, 35.2), P(15.0, 4.3), P(8.4)
                }
            }, {
                {
                    P(-44.9), P(27.6, 8.2), P(6.4, 48.7, 33.0), P(-25.1, -4.2)
                }
            }, {
                {
                    P(15.4, 13.2), P(-12.1), P(29.6, -14.8, -1.0), P(-1.7, 25.9)
                }
            }, {
                {
                    P(1.6, 17.6), P(-47.9, -10.9), P(-22.1, -17.5), P(-17.8, -34.5)
                }
            }, {
                {
                    P(13.9, -30.9, -22.2), P(31.0, -32.6), P(38.4), P(39.5, 35.8)
                }
            }, {
                {
                    P(-5.3, -45.7), P(-3.0, -5.7, 44.5), P(-6.3, -2.4), P(37.2)
                }
            }, {
                {
                    P(5.5), P(31.7, 36.1), P(31.9, -22.9), P(2.8, -47.2, 15.4)
                }
            }, {
                {
                    P(28.5, 23.7, 17.5), P(17.9), P(22.1, 19.7, 33.7), P(22.5)
                }
            }, {
                {
                    P(10.0, -19.4), P(-33.6, -25.3, 28.7), P(24.4, 48.6), \
                        P(20.7, -48.6)
                }
            }, {
                {
                    P(34.3), P(-21.5, 49.3), P(-27.4, -4.5), P(-17.4, -2.2, -9.8)
                }
            }
        }
    };

    for (auto & line: arr) {
        Point & A = line[0];
        Point & B = line[1];
        Midpoint m1(A, B);
        Point & C = line[2];
        Point & D = line[3];
        Midpoint m2(C, D);
        Distance d(m1, m2);
        cout << "\nMidpoint AB: "\ <<
            "(" << A << "), (" << B << ") = "\ <<
            m1 << endl;
        cout << "Midpoint CD: "\ <<
            "(" << C << "), (" << D << ") = "\ <<
            m2 << endl;
        cout << "Distance(Midpoint AB, Midpoint CD): " << d << endl;
    }
    
    return 0;
}