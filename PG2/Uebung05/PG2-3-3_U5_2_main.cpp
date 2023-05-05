#include "person.h"
#include <vector>
#include <system_error>

int main(){
     std::vector<struct PStruct> v;

     struct PStruct p1;

     struct PStruct p2 = {};
     
     struct PStruct* p3 = new struct PStruct;
     
     if(p3 == nullptr)
     {
          return static_cast<int>(std::errc::not_enough_memory);
     }
     p3->s_ = "Smith";
     p3->e_ = EyeColor::Green;
     p3->h_ = 1.78;
     p3->g_ = 1;

     v.push_back(p1);
     v.push_back(p2);
     v.push_back(*p3);

     for(auto& p: v)
     {
          std::cout << p << std::endl;
     }

     delete p3;

     return 0;
}
