//
// Created by pablo on 10/4/22.
//
#ifndef MEMORIA_PROYECTO1_CLIENTEMEM_H
#define MEMORIA_PROYECTO1_CLIENTEMEM_H

/**SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS*/
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#define PORT 8080
#include <netdb.h>
#include <QApplication>
#include <QComboBox>
/**   GUI    GUI    GUI    GUI    GUI    GUI    GUI    GUI    GUI         */
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QCoreApplication>
#include <QMainWindow>
#include <iostream>
#include <sstream>
class clienteMem: public QMainWindow{
Q_OBJECT
public:
/**SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS*/
    struct sockaddr_in addr;
    char buffer[1024];
    int server;
    int escogencia;
    char mensaje[1024];


/**   GUI    GUI    GUI    GUI    GUI    GUI    GUI    GUI    GUI         */
    explicit  clienteMem(QWidget *parent =0);
    virtual ~clienteMem();
    void posicion_aux(int num);

    /**
 * Estos botones reppresentas las tarjetas en juego.
 * */
    QWidget ventana;
    QPushButton * boton0  = new QPushButton(&ventana);QPushButton * boton1  = new QPushButton(&ventana);
    QPushButton * boton2  = new QPushButton(&ventana);QPushButton * boton3  = new QPushButton(&ventana);
    QPushButton * boton4  = new QPushButton(&ventana);QPushButton * boton5  = new QPushButton(&ventana);
    QPushButton * boton6  = new QPushButton(&ventana);QPushButton * boton7  = new QPushButton(&ventana);
    QPushButton * boton8  = new QPushButton(&ventana);QPushButton * boton9  = new QPushButton(&ventana);
    QPushButton * boton10 = new QPushButton(&ventana);QPushButton * boton11 = new QPushButton(&ventana);
    QPushButton * boton12 = new QPushButton(&ventana);QPushButton * boton13 = new QPushButton(&ventana);
    QPushButton * boton14 = new QPushButton(&ventana);QPushButton * boton15 = new QPushButton(&ventana);
    QPushButton * boton16 = new QPushButton(&ventana);QPushButton * boton17 = new QPushButton(&ventana);
    QPushButton * boton18 = new QPushButton(&ventana);QPushButton * boton19 = new QPushButton(&ventana);
    QPushButton * boton20 = new QPushButton(&ventana);QPushButton * boton21 = new QPushButton(&ventana);
    QPushButton * boton22 = new QPushButton(&ventana);QPushButton * boton23 = new QPushButton(&ventana);
    QPushButton * boton24 = new QPushButton(&ventana);QPushButton * boton25 = new QPushButton(&ventana);
    QPushButton * boton26 = new QPushButton(&ventana);QPushButton * boton27 = new QPushButton(&ventana);
    QPushButton * boton28 = new QPushButton(&ventana);QPushButton * boton29 = new QPushButton(&ventana);

    QPushButton * boton30 = new QPushButton(&ventana);QPushButton * boton31 = new QPushButton(&ventana);
    QPushButton * boton32 = new QPushButton(&ventana);QPushButton * boton33 = new QPushButton(&ventana);
    QPushButton * boton34 = new QPushButton(&ventana);QPushButton * boton35 = new QPushButton(&ventana);
    QPushButton * boton36 = new QPushButton(&ventana);QPushButton * boton37 = new QPushButton(&ventana);
    QPushButton * boton38 = new QPushButton(&ventana);QPushButton * boton39 = new QPushButton(&ventana);
    QPushButton * boton40 = new QPushButton(&ventana);QPushButton * boton41 = new QPushButton(&ventana);
    QPushButton * boton42 = new QPushButton(&ventana);QPushButton * boton43 = new QPushButton(&ventana);
    QPushButton * boton44 = new QPushButton(&ventana);QPushButton * boton45 = new QPushButton(&ventana);
    QPushButton * boton46 = new QPushButton(&ventana);QPushButton * boton47 = new QPushButton(&ventana);
    QPushButton * boton48 = new QPushButton(&ventana);QPushButton * boton49 = new QPushButton(&ventana);
    QPushButton * boton50 = new QPushButton(&ventana);QPushButton * boton51 = new QPushButton(&ventana);
    QPushButton * boton52 = new QPushButton(&ventana);QPushButton * boton53 = new QPushButton(&ventana);
    QPushButton * boton54 = new QPushButton(&ventana);QPushButton * boton55 = new QPushButton(&ventana);
    QPushButton * boton56 = new QPushButton(&ventana);QPushButton * boton57 = new QPushButton(&ventana);
    QPushButton * boton58 = new QPushButton(&ventana);QPushButton * boton59 = new QPushButton(&ventana);
    //QPushButton * boton9 = new QPushButton("GIRAR", &ventana);
/***********************************************************************************************************************/
    QPushButton * b_enviar = new QPushButton("ENVIAR",&ventana);
    QPushButton * b_recibir = new QPushButton("RECIBIR",&ventana);
    QPushButton * b_conectar = new QPushButton("CONECTAR",&ventana);
    QLabel      * eti = new QLabel(&ventana);
    QLabel      * label_escogencia = new QLabel(&ventana);
    QComboBox   * cb_sockets= new QComboBox(&ventana);

private slots:
/**SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS*/
    //void interfaz();
    void Cliente();
    void Enviar();
    void Recibir();
    void CerrarSocket();
    void posicion0();void posicion1();void posicion2();void posicion3();void posicion4();
    void posicion5();void posicion6();void posicion7();void posicion8();void posicion9();

    void posicion10();void posicion11();void posicion12();void posicion13();void posicion14();
    void posicion15();void posicion16();void posicion17();void posicion18();void posicion19();

    void posicion20();void posicion21();void posicion22();void posicion23();void posicion24();
    void posicion25();void posicion26();void posicion27();void posicion28();void posicion29();

    void posicion30();void posicion31();void posicion32();void posicion33();void posicion34();
    void posicion35();void posicion36();void posicion37();void posicion38();void posicion39();

    void posicion40();void posicion41();void posicion42();void posicion43();void posicion44();
    void posicion45();void posicion46();void posicion47();void posicion48();void posicion49();

    void posicion50();void posicion51();void posicion52();void posicion53();void posicion54();
    void posicion55();void posicion56();void posicion57();void posicion58();void posicion59();
    /**
    void faseTapeDestape();
    void handleButton0();
    void handleButton1();
    void handleButton2();
    void handleButton3();
    void handleButton4();
    void handleButton5();
    void handleButton6();
    void handleButton7();
*/
};
#endif //MEMORIA_PROYECTO1_CLIENTEMEM_H
