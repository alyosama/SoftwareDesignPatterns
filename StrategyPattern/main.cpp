#include <iostream>
#include "robot.h"
#include "aggressivebehavioral.h"
#include "defensivebehavioral.h"
#include "normalbehavioral.h"
#include "ibehavioral.h"
using namespace std;

int main()
{
    Robot r1("Big Robot");
    Robot r2("George v.2.1");
    Robot r3("R2");

    r1.setBehavioralStrategy(new AggressiveBehavioral);
    r2.setBehavioralStrategy(new DefensiveBehavioral);
    r3.setBehavioralStrategy(new NormalBehavioral);

    r1.move();
    r2.move();
    r3.move();

   std::cout<<"\r\nNew behaviours: "<<
            "\r\n\t'Big Robot' gets really scared"<<
            "\r\n\t, 'George v.2.1' becomes really mad because"<<
            "it's always attacked by other robots"<<
            "\r\n\t and R2 keeps its calm\r\n";

    r1.setBehavioralStrategy(new DefensiveBehavioral);
    r2.setBehavioralStrategy(new AggressiveBehavioral);

    r1.move();
    r2.move();
    r3.move();

    return 0;
}

