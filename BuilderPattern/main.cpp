#include <string>
#include <iostream>
using namespace std;

class CDesktop
{

public:
    void SetRAM(const string& sRAM)                 { m_sRAM = sRAM;                 }
    void SetProcessor(const string& sProcessor)     { m_sProcessor = sProcessor;     }
    void SetMotherBoard(const string& sMotherBoard) { m_sMotherBoard = sMotherBoard; }
    void SetMonitor(const string& sMonitor)         { m_sMonitor = sMonitor;         }
    void SetKeyboard(const string& sKeyboard)       { m_sKeyboard = sKeyboard;       }
    void SetMouse(const string& sMouse)             { m_sMouse = sMouse;             }
    void SetSpeaker(const string& sSpeaker)         { m_sSpeaker = sSpeaker;         }

    void Start() {
        cout<<"Starting the Computer With the Config:\n";
        cout<<"RAM:"<<m_sRAM<<"\n";
        cout<<"Processor:"<<m_sProcessor<<"\n";
        cout<<"MotherBoard:"<<m_sMotherBoard<<"\n";
        cout<<"Monitor:"<<m_sMonitor<<"\n";
        cout<<"Keyboard:"<<m_sKeyboard<<"\n";
        cout<<"Mouse:"<<m_sMouse<<"\n";
        cout<<"Speaker:"<<m_sSpeaker<<"\n";
    }

private:
    string m_sMonitor;
    string m_sKeyboard;
    string m_sMouse;
    string m_sSpeaker;
    string m_sRAM;
    string m_sProcessor;
    string m_sMotherBoard;
};

class IDesktopBuilder
{
public:
    virtual ~ IDesktopBuilder() {}
    CDesktop* GetDesktop() { return m_pDesktop; }
    void CreateNewDesktop()  { m_pDesktop = new CDesktop(); }
    virtual void BuidMonitor()      = 0;
    virtual void BuildKeyBoard()    = 0;
    virtual void BuidMouse()        = 0;
    virtual void BuildRAM()         = 0;
    virtual void BuidProcessor()    = 0;
    virtual void BuidSpeaker()      = 0;
    virtual void BuildMotherBoard() = 0;
private:
    string m_sRAM;
    string m_sProcessor;
    string m_sMotherBoard;
    string m_sMonitor;
    string m_sKeyboard;
    string m_sMouse;
    string m_sSpeaker;
protected:
    CDesktop* m_pDesktop;
};

class DellDesktopBuilder : public IDesktopBuilder
{
public:
    void BuidMonitor()      { m_pDesktop->SetMonitor("Dell Monitor"); }
    void BuildKeyBoard()    { m_pDesktop->SetKeyboard("Dell Keyboard"); }
    void BuidMouse()        { m_pDesktop->SetMouse("Dell Mouse");}
    void BuildRAM()         { m_pDesktop->SetRAM("Hynet DDR3 ");}
    void BuidProcessor()    { m_pDesktop->SetProcessor("Intel I6");}
    void BuidSpeaker()      { m_pDesktop->SetSpeaker("Dell Speaker");}
    void BuildMotherBoard() { m_pDesktop->SetMotherBoard("Gigabyte");}
};

class AcerDesktopBuilder : public IDesktopBuilder
{
public:
    void BuidMonitor()      { m_pDesktop->SetMonitor("Acer Monitor"); }
    void BuildKeyBoard()    { m_pDesktop->SetKeyboard("Acer Keyboard"); }
    void BuidMouse()        { m_pDesktop->SetMouse("Acer Mouse");}
    void BuildRAM()         { m_pDesktop->SetRAM("Hynet DDR3 ");}
    void BuidProcessor()    { m_pDesktop->SetProcessor("Intel I6");}
    void BuidSpeaker()      { m_pDesktop->SetSpeaker("Acer Speaker");}
    void BuildMotherBoard() { m_pDesktop->SetMotherBoard("Gigabyte");}
};

class ComputerShopDirector
{
public:
 void SetDesktopBuilder(IDesktopBuilder* pBuilder) { m_pBuilder = pBuilder;           }
 CDesktop* GetDesktop()                            { return m_pBuilder->GetDesktop(); }

 void BuildDesktop(){
     m_pBuilder->CreateNewDesktop();
     m_pBuilder->BuidMonitor();
     m_pBuilder->BuidMouse();
     m_pBuilder->BuildRAM();
     m_pBuilder->BuidProcessor();
     m_pBuilder->BuildKeyBoard();
     m_pBuilder->BuidSpeaker();
     m_pBuilder->BuildMotherBoard();
 }

private:
    IDesktopBuilder* m_pBuilder;
};

//client
void BuilderPatterClient()
{
    ComputerShopDirector director;
    IDesktopBuilder* pBuilder = new AcerDesktopBuilder();
    director.SetDesktopBuilder(pBuilder);
    director.BuildDesktop();
    CDesktop* pDesktop = director.GetDesktop();
    pDesktop->Start();
}
