#ifndef NORMALFIRE
#define NORMALFIRE


#include "ifire.h"
#include <iostream>


class NormalFire :public IFire {
public:
    int moveCommand(){
        std::cout<<"\Normal Fire"<<std::endl;
        return 0;
    }
};


#endif // NORMALFIRE

