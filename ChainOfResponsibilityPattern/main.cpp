#include<iostream>

using namespace std;

const int FRONT_END_HELP = 0;
const int INTERMEDIATE_LAYER_HELP = 1;
const int GENERAL_HELP = 2;

class HelpInterface
{
public:
    virtual void getHelp(int iHelpConstant) = 0;
};

class FrontEnd : public HelpInterface {
    HelpInterface * Successor;

public:
        FrontEnd(HelpInterface * s){ Successor = s;}
        void getHelp(int iHelpConstant);
};

void FrontEnd::getHelp(int iHelpConstant)
{
    if (FRONT_END_HELP == iHelpConstant)    {
        cout<<"This is the front end, don't you like it ?\n"<<endl;
    } else {
        Successor->getHelp(iHelpConstant);
    }
}

class IntermediateLayer : public HelpInterface{
      HelpInterface * Successor;
public:
    IntermediateLayer(HelpInterface * s) {Successor = s;}
    void getHelp(int iHelpConstant);
};

void IntermediateLayer::getHelp(int iHelpConstant)
{
    if (INTERMEDIATE_LAYER_HELP == iHelpConstant ) {
        cout<<"This is intermediate layer, nice eh?\n"<<endl;
    } else {
        Successor->getHelp(iHelpConstant);
    }
}

class Application : public HelpInterface{

public:
    Application() {}
    void getHelp(int iHelpConstant) {
        cout<<"This the application help\n"<<endl;
    }
};

int main()
{
    Application *app = new Application();
    IntermediateLayer *ilayer = new IntermediateLayer(app);
    FrontEnd * fend = new FrontEnd(ilayer);
    fend->getHelp(GENERAL_HELP);
    fend->getHelp(INTERMEDIATE_LAYER_HELP);


}
