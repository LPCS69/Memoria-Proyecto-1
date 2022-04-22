//
// Created by pablo on 8/4/22.
//

#ifndef MEMORIA_PROYECTO1_SERVIDORMEMEMORIA_H
#define MEMORIA_PROYECTO1_SERVIDORMEMEMORIA_H
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
class servidorMememoria: public QMainWindow{
        Q_OBJECT
        public:

        int server, client;
        char buffer[1024];
        char mensaje[1024];

        struct sockaddr_in server_addr;
        struct sockaddr_in client_addr;
        socklen_t size;
        explicit  servidorMememoria(QWidget *parent = nullptr);
        virtual ~servidorMememoria();
        void barajar();
        void cortar_baraja();
        void remplazo();
        void refrescar_botones();
        void limpiar_botones();
        void mostrar_variables_enDisco();
        void mostrar_imagenes_enjuego();
        void mostrar_posiciones_asignadas();
        void cargar_datos_enmemoria();
        void referencias_posiciones();
        void respaldo_imagenesenmemoria();
        void cargar_respaldo();
        void encontrar_pareja();
        QWidget ventana;
        QVector <int> tarjetasTapadas{0,1,2,3,4,5,6,7};
        QVector <int> encontradas{};
        int turno =1;
        int parejas_jugador1 = 0;
        int parejas_jugador2 = 0;
        QVector <QString> imagenes_enmemoria;
        int imagen_seleccion;
        QString seleccion_jugador;
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
        int limite_destape = 2;
        QVector <QString> tarjetas_seleccionadas;
        QVector <QString> imagenes_destapadas;
        QString posiciones_asignadas;
        QString sin_cargar;
        QString imagenes_enjuego;

        QLabel      * label_espacio = new QLabel(&ventana);
        QLabel      * label_enDisco = new QLabel(&ventana);
        QLabel      * label_posiciones = new QLabel(&ventana);
        QLabel      * label_imagenes = new QLabel(&ventana);
        QLabel      * label_turno_enjuego = new QLabel( & ventana);
        QLabel      * label_jugador1 = new QLabel( & ventana);
        QLabel      * label_jugador2 = new QLabel( & ventana);
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
/***********************************************************************************************************************/
    QPushButton * boton_enviar = new QPushButton("ENVIAR",&ventana);
    QPushButton * boton_recibir = new QPushButton("RECIBIR",&ventana);
    QPushButton * boton_conectar = new QPushButton("CONECTAR",&ventana);
    QLabel      * eti = new QLabel(&ventana);

private slots:
        void paginacion();
        void quitar();
        void Enviar();
        void Server();
        void Recibir();
        void buscar_imagen();

};



#endif //MEMORIA_PROYECTO1_SERVIDORMEMEMORIA_H
