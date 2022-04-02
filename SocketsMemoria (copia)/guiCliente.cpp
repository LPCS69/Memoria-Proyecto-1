//
// Created by pablo on 31/3/22.
//

#include "guiCliente.h"

guiCliente::guiCliente(QWidget *parent): QMainWindow(parent) {

}

void guiCliente::interfaz() {
    ventana.resize(400, 400);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Servidor");
    ventana.show();
}
guiCliente::~guiCliente(){
    /**
     * add_executable(SocketsMemoria main.cpp cmake-build-debug/server.cpp
        cmake-build-debug/client.cpp cmake-build-debug/guiServer.cpp
        cmake-build-debug/guiServer.h)
    */
}

