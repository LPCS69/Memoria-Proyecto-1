//
// Created by pablo on 16/04/22.
//
#include "mainGUI.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    new mainGUI;
    return app.exec();
}

