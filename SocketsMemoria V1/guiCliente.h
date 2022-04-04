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

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#define PORT 8080
#include <netdb.h>
#include "threadGUI.h"
#include <QApplication>
#include<thread>
class threadGUI;
class guiCliente: public QMainWindow
        {
Q_OBJECT
        public:
    struct sockaddr_in addr;
    char buffer[1024];
    int server;
    char mensaje;

public:
    explicit guiCliente(QWidget *parent = 0);
    void interfaz();
    void Client();
    void Enviar();
    void Recibir();
    void CerrarSocket();

    virtual ~guiCliente();
    QWidget ventana;
    QPushButton * boton = new QPushButton(&ventana);
    QLabel * eti = new QLabel(&ventana);
private slots:
    //threadGUI *mThread;
    void conexion();

};


#endif //SOCKETSMEMORIA_GUICLIENTE_H
