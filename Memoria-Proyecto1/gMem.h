//
// Created by pablo on 8/4/22.
//

#ifndef MEMORIA_PROYECTO1_GMEM_H
#define MEMORIA_PROYECTO1_GMEM_H
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
class gMem: public QMainWindow{
        Q_OBJECT
        public:
        explicit  gMem(QWidget *parent = nullptr);
        virtual ~gMem();
        void cola_aleatoria();
        void cargar_nuevo();
        void refrescar_botones();
        void cargar_espacios_libres();
        void mostrar_variables_enDisco();
        QWidget ventana;
        QVector <int> tarjetasTapadas{0,1,2,3,4,5,6,7};
        QVector <int> tarjetasDestapadas{};
        QVector <int> encontradas{};
        int aleatorio;
        QQueue <int> enmemoria;
        QVector <QString> tarjetas {"c0","c1","c2","c3","c4","c5","c6","c7","c8","c9","c10","c11","c12","c13","c14","c15","c16",
                                    "c17","c18","c19","c20","c21","c22","c23","c24","c25","c26","c27","c28","c29"};
        int espacio_enmemoria;
        bool destape = true;
        int limite_destape = 2;
        int cont_destape = 0;
        QString sin_cargar;
        QLabel * label_espacio = new QLabel(&ventana);
        QLabel * label_enDisco = new QLabel(&ventana);
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
    private slots:
        void paginacion();
        void quitar();
    };



#endif //MEMORIA_PROYECTO1_GMEM_H
