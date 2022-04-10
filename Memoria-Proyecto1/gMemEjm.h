//
// Created by pablo on 8/4/22.
//

#ifndef MEMORIA_PROYECTO1_GMEMEJM_H
#define MEMORIA_PROYECTO1_GMEMEJM_H
#include <QString>
#include <QPushButton>
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QQueue>
#include <stdlib.h>
#include <time.h>

class gMemEjm: public QMainWindow{
Q_OBJECT
public:
    explicit  gMemEjm(QWidget *parent = nullptr);
    virtual ~gMemEjm();
    void cola_aleatoria();
    void cargar_nuevo();
    void refrescar_botones();
    QWidget ventana;
    QVector <int> tarjetasTapadas{0,1,2,3,4,5,6,7};
    QVector <int> tarjetasDestapadas{};
    QVector <int> encontradas{};
    int aleatorio;
    QQueue <int> enmemoria;
    //QVector <QString> tarjetas {"c0","c1","c2","c3","c4","c5","c6","c7","c8","c9","c10","c11","c12","c13"};
    QVector <QString> tarjetas {"QWidget {background-color:green}","QWidget {background-color:red}","QWidget {background-color:yellow}",
                                "QWidget {background-color:white}","QWidget {background-color:blue}","QWidget {background-color:orange}",
                                "QWidget {background-color:purple}","QWidget {background-color:red}","QWidget {background-color:orange}",
                                "QWidget {background-color:blue}","QWidget {background-color:white}","QWidget {background-color:yellow}",
                                "QWidget {background-color:blue}","QWidget {background-color:green}"};

    bool destape = true;
    int limite_destape = 2;
    int cont_destape = 0;
    QPushButton * boton0 = new QPushButton("Memoria", &ventana);
    QPushButton * boton1 = new QPushButton( &ventana);
    QPushButton * boton2 = new QPushButton(&ventana);
    QPushButton * boton3 = new QPushButton(&ventana);
private slots:
    void paginacion();
};



#endif //MEMORIA_PROYECTO1_GMEMEJM_H
