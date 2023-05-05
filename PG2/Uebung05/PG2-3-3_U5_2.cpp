#include 'person.h'

int main(){


     std::vector<struct PStruct> v;

     struct PStruct p1;

     struct PStruct p2 = {0};
     
     struct PStruct * p3 = new struct PStruct;
     p3.s_ = 'Smith';
     p3.e_ = EyeColor::Green;
     p3.h_ = 1.78;
     p3.g_ = 1;

     v.push_back(p1);
     v.push_back(p2);
     v.push_back(p3);

     return 0;
}