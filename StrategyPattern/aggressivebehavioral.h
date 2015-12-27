#ifndef AGGRESSIVEBEHAVIORAL
#define AGGRESSIVEBEHAVIORAL

#include "ibehavioral.h"
#include <iostream>

class AggressiveBehavioral :public IBehavioral {
public:
    int moveCommand(){
        std::cout<<"\tAgressive Behaviour: if find another robot attack it"<<std::endl;
        return 1;
    }
};

#endif // AGGRESSIVEBEHAVIORAL

