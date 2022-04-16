//
// Created by pablo on 18/3/22.
//

#ifndef MEMORIA_PROYECTO1_MAINGUI_H
#define MEMORIA_PROYECTO1_MAINGUI_H
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
#include <string>
class mainGUI: public QMainWindow{
    Q_OBJECT
public:
    explicit  mainGUI(QWidget *parent =0);
    virtual ~mainGUI();
    void encontrarParejas();
    void quitarEncontradas(int);
    QWidget ventana;
    QVector <int> tarjetasTapadas{0,1,2,3,4,5,6,7};
    QVector <int> tarjetasDestapadas{};
    QVector <int> encontradas{};
    QVector <QString> tarjetas {"c0","c3","c2","c1","c3","c2","c0","c1"};
    bool destape = true;
    int limite_destape = 2;
    int cont_destape = 0;
    QPushButton * boton0 = new QPushButton("GIRAR", &ventana);
    QPushButton * boton1 = new QPushButton("GIRAR", &ventana);
    QPushButton * boton2 = new QPushButton("GIRAR", &ventana);
    QPushButton * boton3 = new QPushButton("GIRAR", &ventana);
    QPushButton * boton4 = new QPushButton("GIRAR", &ventana);
    QPushButton * boton5 = new QPushButton("GIRAR", &ventana);
    QPushButton * boton6 = new QPushButton("GIRAR", &ventana);
    QPushButton * boton7 = new QPushButton("GIRAR", &ventana);
    QPushButton * boton9 = new QPushButton(QIcon(QPixmap("Front-Card")), nullptr,& ventana);

private slots:

    void faseTapeDestape();
    void handleButton0();
    void handleButton1();
    void handleButton2();
    void handleButton3();
    void handleButton4();
    void handleButton5();
    void handleButton6();
    void handleButton7();

};



#endif //MEMORIA_PROYECTO1_MAINGUI_H
