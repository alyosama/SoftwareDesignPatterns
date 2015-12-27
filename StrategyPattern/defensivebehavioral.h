#ifndef DEFENSIVEBEHAVIORAL
#define DEFENSIVEBEHAVIORAL

#include "ibehavioral.h"
#include <iostream>

class DefensiveBehavioral :public IBehavioral {
public:
    int moveCommand(){
        std::cout<<"\tDefensive Behaviour: if find another robot run from it"<<std::endl;
        return -1;
    }
};


#endif // DEFENSIVEBEHAVIORAL

