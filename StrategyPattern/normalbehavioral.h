#ifndef NORMALBEHAVIORAL
#define NORMALBEHAVIORAL

#include "ibehavioral.h"
#include <iostream>

class NormalBehavioral :public IBehavioral {
public:
    int moveCommand(){
        std::cout<<"\tNormal Behaviour: if find another robot ignore it"<<std::endl;
        return 0;
    }
};


#endif // NORMALBEHAVIORAL

