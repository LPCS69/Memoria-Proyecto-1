//
// Created by pablo on 14/4/22.
//
#include "clienteMemoria.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    new clienteMemoria;
    return app.exec();
}

