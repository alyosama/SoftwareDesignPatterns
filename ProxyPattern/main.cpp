#include <iostream>
using namespace std;

class Node {
public:
    virtual void open() = 0;
};

class File : public Node {
public:
    File() {
    }
    virtual void open() {
        cout << "Open real File." << endl;
    }
};

class Shortcut : public Node {
public:
    virtual void open() {
        if(file == NULL) {
            file = new File();
            cout << "File is assigned." << endl;
        }
        file->open();
    }
private:
    File* file;
};

int main() {

    Node* shortcut = new Shortcut();
    shortcut->draw();
    shortcut->draw();
    shortcut->draw();
    return 0;
}
