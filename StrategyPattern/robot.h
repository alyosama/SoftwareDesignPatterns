#ifndef ROBOT_H
#define ROBOT_H

#include "ifire.h"
#include "ibehavioral.h"
#include <string>
class Robot
{
    std::string name;
    IFire * fireStrategy;
    IBehavioral* behavioralStrategy;

public:
    Robot();
    Robot(std::string name){this->name=name;}
    ~Robot();
    void move();
    void fire();
    std::string getName(){return this->name;}
    void setName(std::string name){this->name=name;}
    IFire* getFireStrategy(){return this->fireStrategy;}
    void setFireStrategy(IFire* fireStrategy){this->fireStrategy=fireStrategy;}
    IBehavioral* getBehavioralStrategy(){return this->behavioralStrategy;}
    void setBehavioralStrategy(IBehavioral* behavioralStrategy){this->behavioralStrategy=behavioralStrategy;}
};

#endif // ROBOT_H
