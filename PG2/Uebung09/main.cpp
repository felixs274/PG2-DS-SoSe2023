#include "abstrClass.h"

using namespace std;

int main(){

    Figure * pF[3];

    pF[0] = new Line(P(1.1, 1.2));
    pF[1] = new Ellipse(P(2.1, 2.2));
    pF[2] = new Circle(P(3.1, 3.2));

    for (auto item : pF) {
        cout << *item;
    }

    for (auto item: pF) {
        item -> print2(cout);
    }

    return 0;
}