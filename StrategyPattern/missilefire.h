#ifndef MISSILEFIRE
#define MISSILEFIRE

#include "ifire.h"
#include <iostream>


class MissileFire :public IFire {
public:
    int moveCommand(){
        std::cout<<"\Missile Fire"<<std::endl;
        return 1;
    }
};


#endif // MISSILEFIRE

