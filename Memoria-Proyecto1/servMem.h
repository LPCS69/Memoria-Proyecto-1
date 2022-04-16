//
// Created by pablo on 8/4/22.
//

#ifndef MEMORIA_PROYECTO1_SERVMEM_H
#define MEMORIA_PROYECTO1_SERVMEM_H
#include <QString>
#include <QPushButton>
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QQueue>
#include <stdlib.h>
#include <time.h>
#include <QLabel>
#include <string>
#include <QComboBox>
#include <QVBoxLayout>

#include <QAction>
#include <QObject>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#define PORT 8080
#include <netdb.h>
class servMem: public QMainWindow{
        Q_OBJECT
        public:

        int server, client;
        int bufsize = 1024;
        char buffer[1024];
        char mensaje[1024];

        struct sockaddr_in server_addr;
        struct sockaddr_in client_addr;
        socklen_t size;
        explicit  servMem(QWidget *parent = nullptr);
        virtual ~servMem();
        void cola_aleatoria();
        void barajar();
        void cortar_baraja();
        void referencias_busqueda();
        void remplazo();
        void refrescar_botones();
        void cargar_espacios_libres();
        void mostrar_variables_enDisco();
        void mostrar_posiciones_asignadas();
        void cargar_datos_enmemoria();
        void referencias_posiciones();
        QWidget ventana;
        QVector <int> tarjetasTapadas{0,1,2,3,4,5,6,7};
        QVector <int> tarjetasDestapadas{};
        QVector <int> encontradas{};
        int seleccion;
        int aleatorio;
        QQueue <int> enmemoria;
        QQueue <QObject> tarjetas_enmemoria;
        QVector <QString> tarjetas {"c0","c1","c2","c3","c4","c5","c6","c7","c8","c9",
                                    "c10","c11","c12","c13","c14","c15","c16","c17","c18","c19",
                                    "c20","c21","c22","c23","c24","c25","c26","c27","c28","c29"};
        QVector <QString> posiciones {"0","1","2","3","4","5","6","7","8","9",
                                  "10","11","12","13","14","15","16","17","18","19",
                                  "20","21","22","23","24","25","26","27","28","29",
                                  "30","31","32","33","34","35","36","37","38","39",
                                  "40","41","42","43","44","45","46","47","48","49",
                                  "50","51","52","53","54","55","56","57","58","59"};
        QVector <QString> posiciones_barajadas;
        QVector <QVector <QString>> posiciones_imagenes;
        int espacio_enmemoria;
        bool destape = true;
        int limite_destape = 2;
        int cont_destape = 0;
        QString posiciones_asignadas;
        QString sin_cargar;
        QComboBox   * cb = new QComboBox(&ventana);
        QComboBox   * cb_posiciones = new QComboBox(&ventana);
        QLabel      * label_espacio = new QLabel(&ventana);
        QLabel      * label_enDisco = new QLabel(&ventana);
        QLabel      * label_posiciones = new QLabel(&ventana);
        QLabel      * label_referencias = new QLabel(&ventana);
        QLabel      * label_imagenes = new QLabel(&ventana);
        QLabel      * label_busqueda = new QLabel(&ventana);
        QPushButton * boton0 = new QPushButton("Memoria", &ventana);
        QPushButton * boton1 = new QPushButton( &ventana);
        QPushButton * boton2 = new QPushButton(&ventana);
        QPushButton * boton3 = new QPushButton(&ventana);
        QPushButton * boton4 = new QPushButton(&ventana);
        QPushButton * boton5 = new QPushButton(&ventana);
        QPushButton * boton6 = new QPushButton(&ventana);
        QPushButton * boton7 = new QPushButton(&ventana);
        QPushButton * boton8 = new QPushButton(&ventana);
        QPushButton * boton9 = new QPushButton(&ventana);
        QPushButton * boton10 = new QPushButton(&ventana);
        QPushButton * boton11 = new QPushButton("Quitar", &ventana);
        QPushButton * boton_posiciones = new QPushButton("Posiciones", &ventana);
/***********************************************************************************************************************/
    QPushButton * b_enviar = new QPushButton("ENVIAR",&ventana);
    QPushButton * b_recibir = new QPushButton("RECIBIR",&ventana);
    QPushButton * b_conectar = new QPushButton("CONECTAR",&ventana);
    QPushButton * b_buscar = new QPushButton("Buscar",&ventana);
    QComboBox   * cb_buscar = new QComboBox(&ventana);
    QLabel      * eti = new QLabel(&ventana);
    QComboBox   * cb_sockets = new QComboBox(&ventana);

private slots:
        void paginacion();
        void quitar();
        void mostrar_posiciones();
        void Enviar();
        void Server();
        void Recibir();
        void buscar_imagen();

};



#endif //MEMORIA_PROYECTO1_SERVMEM_H
