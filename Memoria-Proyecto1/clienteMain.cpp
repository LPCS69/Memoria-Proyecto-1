//
// Created by pablo on 14/4/22.
//
#include "clienteMem.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    new clienteMem;
    return app.exec();
}

