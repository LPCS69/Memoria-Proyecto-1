//
// Created by pablo on 10/4/22.
//
#ifndef MEMORIA_PROYECTO1_CLIENTEMEMORIA_H
#define MEMORIA_PROYECTO1_CLIENTEMEMORIA_H

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


class clienteMemoria: public QMainWindow{
Q_OBJECT
public:
/**SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS SOCKETS*/
    struct sockaddr_in addr;
    char buffer[1024];
    int server;
    int escogencia;
    int limite_destape = 2;
    char mensaje[1024];
    QString imagen;
    QVector <int> tarjetas_destapadas;
    QVector <QString> imagenes_destapadas;
/**   GUI    GUI    GUI    GUI    GUI    GUI    GUI    GUI    GUI         */
    explicit  clienteMemoria(QWidget *parent =0);
    virtual ~clienteMemoria();
    void posicion_aux(int);
    void girar_tarjeta(int, QString);
    void encontrar_pareja();
    void quitar_pareja(int);
    /**
 * Estos botones reppresentas las tarjetas en juego.
 * */
    QWidget ventana;
    QPushButton * boton0  = new QPushButton( "GIRAR",&ventana);;QPushButton * boton1  = new QPushButton("GIRAR",&ventana);
    QPushButton * boton2  = new QPushButton( "GIRAR",&ventana);;QPushButton * boton3  = new QPushButton("GIRAR",&ventana);
    QPushButton * boton4  = new QPushButton("GIRAR",&ventana);QPushButton * boton5  = new QPushButton("GIRAR",&ventana);
    QPushButton * boton6  = new QPushButton("GIRAR",&ventana);QPushButton * boton7  = new QPushButton("GIRAR",&ventana);
    QPushButton * boton8  = new QPushButton("GIRAR",&ventana);QPushButton * boton9  = new QPushButton("GIRAR",&ventana);
    QPushButton * boton10 = new QPushButton("GIRAR",&ventana);QPushButton * boton11 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton12 = new QPushButton("GIRAR",&ventana);QPushButton * boton13 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton14 = new QPushButton("GIRAR",&ventana);QPushButton * boton15 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton16 = new QPushButton("GIRAR",&ventana);QPushButton * boton17 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton18 = new QPushButton("GIRAR",&ventana);QPushButton * boton19 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton20 = new QPushButton("GIRAR",&ventana);QPushButton * boton21 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton22 = new QPushButton("GIRAR",&ventana);QPushButton * boton23 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton24 = new QPushButton("GIRAR",&ventana);QPushButton * boton25 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton26 = new QPushButton("GIRAR",&ventana);QPushButton * boton27 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton28 = new QPushButton("GIRAR",&ventana);QPushButton * boton29 = new QPushButton("GIRAR",&ventana);

    QPushButton * boton30 = new QPushButton("GIRAR",&ventana);QPushButton * boton31 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton32 = new QPushButton("GIRAR",&ventana);QPushButton * boton33 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton34 = new QPushButton("GIRAR",&ventana);QPushButton * boton35 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton36 = new QPushButton("GIRAR",&ventana);QPushButton * boton37 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton38 = new QPushButton("GIRAR",&ventana);QPushButton * boton39 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton40 = new QPushButton("GIRAR",&ventana);QPushButton * boton41 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton42 = new QPushButton("GIRAR",&ventana);QPushButton * boton43 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton44 = new QPushButton("GIRAR",&ventana);QPushButton * boton45 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton46 = new QPushButton("GIRAR",&ventana);QPushButton * boton47 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton48 = new QPushButton("GIRAR",&ventana);QPushButton * boton49 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton50 = new QPushButton("GIRAR",&ventana);QPushButton * boton51 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton52 = new QPushButton("GIRAR",&ventana);QPushButton * boton53 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton54 = new QPushButton("GIRAR",&ventana);QPushButton * boton55 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton56 = new QPushButton("GIRAR",&ventana);QPushButton * boton57 = new QPushButton("GIRAR",&ventana);
    QPushButton * boton58 = new QPushButton("GIRAR",&ventana);QPushButton * boton59 = new QPushButton("GIRAR",&ventana);

    QLabel*label_numeracion0 = new QLabel(&ventana);QLabel*label_numeracion1= new QLabel(&ventana);
    QLabel*label_numeracion2 = new QLabel(&ventana);QLabel*label_numeracion3 = new QLabel(&ventana);
    QLabel*label_numeracion4 = new QLabel(&ventana);QLabel*label_numeracion5 = new QLabel(&ventana);
    QLabel*label_numeracion6 = new QLabel(&ventana);QLabel*label_numeracion7 = new QLabel(&ventana);
    QLabel*label_numeracion8 = new QLabel(&ventana);QLabel*label_numeracion9 = new QLabel(&ventana);

    QLabel*label_numeracion10 = new QLabel(&ventana);QLabel*label_numeracion11= new QLabel(&ventana);
    QLabel*label_numeracion12 = new QLabel(&ventana);QLabel*label_numeracion13 = new QLabel(&ventana);
    QLabel*label_numeracion14 = new QLabel(&ventana);QLabel*label_numeracion15 = new QLabel(&ventana);
    QLabel*label_numeracion16 = new QLabel(&ventana);QLabel*label_numeracion17 = new QLabel(&ventana);
    QLabel*label_numeracion18 = new QLabel(&ventana);QLabel*label_numeracion19 = new QLabel(&ventana);

    QLabel*label_numeracion20 = new QLabel(&ventana);QLabel*label_numeracion21= new QLabel(&ventana);
    QLabel*label_numeracion22 = new QLabel(&ventana);QLabel*label_numeracion23 = new QLabel(&ventana);
    QLabel*label_numeracion24 = new QLabel(&ventana);QLabel*label_numeracion25 = new QLabel(&ventana);
    QLabel*label_numeracion26 = new QLabel(&ventana);QLabel*label_numeracion27 = new QLabel(&ventana);
    QLabel*label_numeracion28 = new QLabel(&ventana);QLabel*label_numeracion29 = new QLabel(&ventana);

    QLabel*label_numeracion30 = new QLabel(&ventana);QLabel*label_numeracion31= new QLabel(&ventana);
    QLabel*label_numeracion32 = new QLabel(&ventana);QLabel*label_numeracion33 = new QLabel(&ventana);
    QLabel*label_numeracion34 = new QLabel(&ventana);QLabel*label_numeracion35 = new QLabel(&ventana);
    QLabel*label_numeracion36 = new QLabel(&ventana);QLabel*label_numeracion37 = new QLabel(&ventana);
    QLabel*label_numeracion38 = new QLabel(&ventana);QLabel*label_numeracion39 = new QLabel(&ventana);

    QLabel*label_numeracion40 = new QLabel(&ventana);QLabel*label_numeracion41= new QLabel(&ventana);
    QLabel*label_numeracion42 = new QLabel(&ventana);QLabel*label_numeracion43 = new QLabel(&ventana);
    QLabel*label_numeracion44 = new QLabel(&ventana);QLabel*label_numeracion45 = new QLabel(&ventana);
    QLabel*label_numeracion46 = new QLabel(&ventana);QLabel*label_numeracion47 = new QLabel(&ventana);
    QLabel*label_numeracion48 = new QLabel(&ventana);QLabel*label_numeracion49 = new QLabel(&ventana);

    QLabel*label_numeracion50 = new QLabel(&ventana);QLabel*label_numeracion51= new QLabel(&ventana);
    QLabel*label_numeracion52 = new QLabel(&ventana);QLabel*label_numeracion53 = new QLabel(&ventana);
    QLabel*label_numeracion54 = new QLabel(&ventana);QLabel*label_numeracion55 = new QLabel(&ventana);
    QLabel*label_numeracion56 = new QLabel(&ventana);QLabel*label_numeracion57 = new QLabel(&ventana);
    QLabel*label_numeracion58 = new QLabel(&ventana);QLabel*label_numeracion59 = new QLabel(&ventana);
/***********************************************************************************************************************/
    QPushButton * boton_enviar = new QPushButton("ENVIAR",&ventana);
    QPushButton * boton_recibir = new QPushButton("RECIBIR",&ventana);
    QPushButton * boton_conectar = new QPushButton("CONECTAR",&ventana);
    QLabel      * label_recibir = new QLabel(&ventana);
    QLabel      * label_escogencia = new QLabel(&ventana);
   // QComboBox   * cb_sockets= new QComboBox(&ventana);
    bool enviando = false;
    bool conectado = false;
    bool destapar = true;
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

};
#endif //MEMORIA_PROYECTO1_CLIENTEMEMORIA_H
