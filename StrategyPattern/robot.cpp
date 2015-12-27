#include "robot.h"
#include <iostream>

Robot::Robot()
{

}

Robot::~Robot()
{

}

void Robot::fire(){
    std::cout<<this->name<<": Based on Robot Power the fire object decide:\n";
    int command = fireStrategy->fireCommand();
    std::cout<<"\tThe result returned by fire object is sent for the robot \'"<<this->name<<"\'\n";
}

void Robot::move(){
    std::cout<<this->name<<": Based on current position the behaviour object decide the next move:\n";
    int command = behavioralStrategy->moveCommand();
    std::cout<<"\tThe result returned by behaviour object is sent to the movement mechanisms for the robot \'"<<this->name<<"\'\n";
}

