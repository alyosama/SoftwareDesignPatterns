#include <cstring>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Observer
{
public:
    Observer(void);
    virtual void update( Customer *myCust)= 0;
public:
    ~Observer(void);
};


Observer::Observer(void)
{
}

Observer::~Observer(void)
{
}


class Customer
{
public:
    Customer(void);

    void attach( Observer *myObserver);
    void detach( Observer *myObserver);
    string* getState();
    void notifyObs();
private:
    vector myObs;
public:
    ~Customer(void);
};

Customer::Customer(void)
{
}

Customer::~Customer(void)
{
}

void Customer::attach( Observer *myObserver)
{
    myObs.push_back( myObserver);
}

void Customer::detach( Observer *myObserver)
{
    for (int i= 0; i< myObs.size(); i++)
    {
        if (myObs[i]== myObserver)
        {
            myObs.erase(myObs.begin()+i);
            return;
        }
    }
}

void Customer::notifyObs()
{
    // set arg to something that helps
    // tell the Observers what happened
    for (int i= 0; i< myObs.size(); i++)
    {
        myObs[i]->update(this);
    }
}

string* Customer::getState()
{
    string *state= new string;

    // set state

    return 0l;
}

class AddrVerification : public Observer
{
public:
    AddrVerification(void);
    void update( Customer *myCust);
public:
    ~AddrVerification(void);
};

AddrVerification::AddrVerification(void)
{
}

AddrVerification::~AddrVerification(void)
{
}

void AddrVerification::update ( Customer *myCust)
{
}

class WelcomeLetter : public Observer
{
public:
    WelcomeLetter(void);
    void update( Customer *myCust);
public:
    ~WelcomeLetter(void);
};


WelcomeLetter::WelcomeLetter(void)
{
}

WelcomeLetter::~WelcomeLetter(void)
{
}

void WelcomeLetter::update( Customer *myCust)
{

}
