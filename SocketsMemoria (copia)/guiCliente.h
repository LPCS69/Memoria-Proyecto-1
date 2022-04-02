//
// Created by pablo on 31/3/22.
//

#ifndef SOCKETSMEMORIA_GUICLIENTE_H
#define SOCKETSMEMORIA_GUICLIENTE_H
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
class guiCliente: public QMainWindow {
public:
    explicit  guiCliente(QWidget *parent =0);
    virtual ~guiCliente();
    void interfaz();
   Q_OBJECT
public:

    QWidget ventana;

};


#endif //SOCKETSMEMORIA_GUICLIENTE_H
