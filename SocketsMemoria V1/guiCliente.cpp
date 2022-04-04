//
// Created by pablo on 31/3/22.
//

#include "guiCliente.h"
#include "threadGUI.h"
guiCliente::guiCliente(QWidget *parent) : QMainWindow(parent){
    //mThread = new threadGUI(this);
    //mThread->start(QThread::HighestPriority);


}
void guiCliente::Client()
{
    printf("Conectando al servidor...");
    // WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    ::connect(server,(struct sockaddr *)&addr, sizeof(addr));
    printf("Conectado al Servidor!");
}

void guiCliente::Enviar()
{
    printf("Escribe el mensaje a enviar: ");
    *buffer ='a';
    send(server, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    printf("Mensaje enviado!");
    this->Recibir();
}
void guiCliente::Recibir()
{
    recv(server, buffer, sizeof(buffer), 0);
    mensaje = buffer[0];
    eti->setText(QString(mensaje));

    memset(buffer, 0, sizeof(buffer));
}
void guiCliente::CerrarSocket()
{
    ::close(server);
    //WSACleanup();
    printf("Socket cerrado.");
}

void guiCliente::interfaz() {
    ventana.resize(400, 400);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Servidor");
    QSize sizeButton(95,100);
    boton->move(20,90);boton->setFixedSize(sizeButton);
    boton->setStyleSheet("QWidget {background-color:white}");
    boton->setText("CONECTAR");
    connect(boton, SIGNAL (clicked()), this, SLOT(conexion()));
    eti->move(120, 165);
    eti->setStyleSheet("QWidget {background-color:purple}");
    eti->setText(QString(mensaje));
    eti->setFixedSize(120,30);
    ventana.show();
}
void guiCliente::conexion(){
    //this->Client();
    this->Enviar();
};
//server_addr(serverAddr)
//, struct sockaddr_in serverAddr

guiCliente::~guiCliente(){
    /**
     * add_executable(SocketsMemoria main.cpp cmake-build-debug/server.cpp
        cmake-build-debug/client.cpp cmake-build-debug/guiServer.cpp
        cmake-build-debug/guiServer.h)
    */
}

