#include <iostream>
using namespace std;

class Sun;

class State {
public:
        virtual void nextState( Sun* sun ) = 0;
        virtual const char* toString() = 0;
};

class Fagir : public State {
public:
        virtual void nextState( Sun* sun );
        virtual const char* toString() {
                return "Fagir";
        }
};

class Shroq : public State {
public:
        virtual void nextState( Sun* sun );
        virtual const char* toString() {
                return "Shroq";
        }
};

class Thohr : public State {
public:
        virtual void nextState( Sun* sun );
        virtual const char* toString() {
                return "Thohr";
        }
};

class Asr : public State {
public:
        virtual void nextState( Sun* sun );
        virtual const char* toString() {
                return "Asr";
        }
};

class Sun {
public:
        Sun( State* state )
                :_state( state ) {
        }

        void afterSixHours() {
                _state->nextState( this );
        }

        void changeState( State* state ) {
                _state = state;
        }

        const char* getState() {
                return _state->toString();
        }

private:
        State* _state;
};

void Fagir::nextState( Sun* sun ) {
        sun->changeState( new Shroq() );
}

void Shroq::nextState( Sun* sun ) {
        sun->changeState( new Thohr() );
}

void Thohr::nextState( Sun* sun ) {
        sun->changeState( new Asr() );
}

void Asr::nextState( Sun* sun ) {
        sun->changeState( new Fagir() );
}

int main() {

        Sun* sun = new Sun( new Fagir() );
        sun->afterSixHours();
        cout << sun->getState() << endl;

        sun->afterSixHours();
        cout << sun->getState() << endl;

        sun->afterSixHours();
        cout << sun->getState() << endl;

        sun->afterSixHours();
        cout << sun->getState() << endl;

        sun->afterSixHours();
        cout << sun->getState() << endl;

        return 0;
}
