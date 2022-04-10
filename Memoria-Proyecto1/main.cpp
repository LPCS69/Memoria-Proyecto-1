#include "mainGUI.h"
#include "gMem.h"
#include "gMemEjm.h"

#include <QApplication>
using namespace std;
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    //new mainGUI;
    new gMem;
    return app.exec();
}
