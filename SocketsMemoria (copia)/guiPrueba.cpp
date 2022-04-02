//
// Created by pablo on 1/4/22.
//
//
// Created by pablo on 31/3/22.
//


#include <QPushButton>
#include <QLabel>
#include <QAction>
#include <QString>
#include <QPalette>
#include <QObject>
#include <iostream>
#include <QMainWindow>
#include <QCoreApplication>
#include <QVectorIterator>
#include <QThread>
#include <string>

class guiPrueba: public QMainWindow {


public:

    QWidget ventana;


//guiPrueba(QWidget *parent): QMainWindow(parent){
  guiPrueba(){
    ventana.resize(400, 400);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Servidor");
    ventana.show();
    }

};
