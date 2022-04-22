#include "servidorMememoria.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    new servidorMememoria;
    return app.exec();
}
