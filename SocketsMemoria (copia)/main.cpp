#include "guiCliente.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    new guiCliente;
    return app.exec();
}
