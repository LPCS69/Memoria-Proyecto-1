#include "servMem.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    new servMem;
    return app.exec();
}
