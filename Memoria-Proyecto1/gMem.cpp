//
// Created by pablo on 8/4/22.
//

#include "gMem.h"
/**
 * Este metodo se encarga de asignar a una variabnle los datos que no se han cargado en memoria y mostrarlos
 * en una etiqueta.
 */
void gMem::mostrar_variables_enDisco() {
    int cont = 0;
    sin_cargar = "";
    if(enmemoria.empty()){
    while (cont < tarjetas.length()){
            sin_cargar = sin_cargar + "|" + tarjetas.value(cont);
            cb->addItem(tarjetas.value(cont));
            cont++;
    }
    }
    else{
        while (cont < tarjetas.length()){
            if (!enmemoria.contains(cont)){
            sin_cargar = sin_cargar + "|" + tarjetas.value(cont);
            }
            cont++;
        }
    }
    label_enDisco->setText(sin_cargar+"|"+"  ext:"+QString::number(tarjetas.length()));
}

/**
 * Este metodo llena con valores escogidos de forma aleatoria la Cola que simula ser la memoria virtual
 * teniendo de limite la cantidad preestableciada para el tamaño de esta
 */
void gMem::cola_aleatoria(){
    int num;
    srand(time(NULL));

    while(enmemoria.length()<espacio_enmemoria) {
        num = rand() % tarjetas.length();
        if (enmemoria.contains(num)==false){
            enmemoria.push_front(num);}
    }
}
void gMem::remplazo(){
    int num;
    srand(time(NULL));
    num = rand() % tarjetas.length();
    while(enmemoria.contains(num)== true){
        num = rand() % tarjetas.length();}
    enmemoria.pop_back();
    enmemoria.push_front(num);
}

void gMem::cargar_espacios_libres(){
    int num;
    srand(time(NULL));
    num = rand() % tarjetas.length();
    while(enmemoria.length()<espacio_enmemoria){
    while(enmemoria.contains(num)== true){
        num = rand() % tarjetas.length();
    }
    enmemoria.push_front(num);
    }
}

void gMem::refrescar_botones(){
    boton1->setText(tarjetas.value(enmemoria.value(0)));
    if(espacio_enmemoria > 1){boton2->setText(tarjetas.value(enmemoria.value(1)));}
    if(espacio_enmemoria > 2){boton3->setText(tarjetas.value(enmemoria.value(2)));}
    if (espacio_enmemoria > 3){boton4->setText(tarjetas.value(enmemoria.value(3)));}
    if (espacio_enmemoria > 4){boton5->setText(tarjetas.value(enmemoria.value(4)));}
    if (espacio_enmemoria > 5){boton6->setText(tarjetas.value(enmemoria.value(5)));}
    if (espacio_enmemoria > 6){boton7->setText(tarjetas.value(enmemoria.value(6)));}
    if (espacio_enmemoria > 7){boton8->setText(tarjetas.value(enmemoria.value(7)));}
    if (espacio_enmemoria > 8){boton9->setText(tarjetas.value(enmemoria.value(8)));}
    if (espacio_enmemoria > 9){boton10->setText(tarjetas.value(enmemoria.value(9)));}
}

void gMem::paginacion(){
    if(enmemoria.empty()){
        this->cola_aleatoria();
    }
    else{remplazo();}
    refrescar_botones();
    mostrar_variables_enDisco();
}

void gMem::quitar(){
    if(!enmemoria.empty()){
    if (0<tarjetas.length()){

        tarjetas.pop_back();
        enmemoria.removeAll(tarjetas.length());
        espacio_enmemoria = tarjetas.length()/3;
        label_espacio->setText(QString(QString::number(espacio_enmemoria)));
        if (espacio_enmemoria < 10){boton10->close();}; if (espacio_enmemoria < 9){boton9->close();};
        if (espacio_enmemoria <  8){boton8 ->close();}; if (espacio_enmemoria < 7){boton7->close();};
        if (espacio_enmemoria <  6){boton6 ->close();}; if (espacio_enmemoria < 5){boton5->close();};
        if (espacio_enmemoria <  4){boton4 ->close();}; if (espacio_enmemoria < 3){boton3->close();};
        if (espacio_enmemoria <  2){boton2 ->close();}; if (espacio_enmemoria < 1){boton1->close();};

        cargar_espacios_libres();
        refrescar_botones();
        mostrar_variables_enDisco();
    } } };

gMem::gMem(QWidget *parent): QMainWindow(parent) {

    ventana.resize(850, 800);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Gestion de Memoria");

    espacio_enmemoria = tarjetas.length()/3;
    label_espacio->setText(QString(QString::number(espacio_enmemoria)));
    label_espacio->setFixedSize(95,30);
    label_espacio->move(20,435);
    label_espacio->setStyleSheet("QWidget {background-color:red}");

    this->mostrar_variables_enDisco();
    label_enDisco->setFixedSize(825,30);
    label_enDisco->move(20,725);
    label_enDisco->setStyleSheet("QWidget {background-color:blue}");


    cb->setFixedSize(55,30);
    cb->move(135, 205);
    cb->setStyleSheet("QWidget {border: 1px solid white }");
    cb->setStyleSheet("QWidget {background-color:purple}");
    //cb->addItem("A");
    //cb->addItem("B");
    //cb->addItem("C");
    //cb->removeItem(2);
    QSize sizeButton(95,100);

    boton0->move(20,205);boton0->setFixedSize(sizeButton);boton0->setStyleSheet("QWidget {background-color:purple}");
    boton11->move(20,320 );boton11->setFixedSize(sizeButton);boton11->setStyleSheet("QWidget {background-color:yellow}");
    boton1->move(530,90);boton1->setFixedSize(sizeButton);boton1->setStyleSheet("QWidget {background-color:green}");
    boton2->move(530,205);boton2->setFixedSize(sizeButton);boton2->setStyleSheet("QWidget {background-color:green}");
    boton3->move(530,320);boton3->setFixedSize(sizeButton);boton3->setStyleSheet("QWidget {background-color:green}");
    boton4->move(530,435);boton4->setFixedSize(sizeButton);boton4->setStyleSheet("QWidget {background-color:green}");
    boton5->move(530,550);boton5->setFixedSize(sizeButton);boton5->setStyleSheet("QWidget {background-color:green}");
    boton6->move(745,90);boton6->setFixedSize(sizeButton);boton6->setStyleSheet("QWidget {background-color:green}");
    boton7->move(745,205);boton7->setFixedSize(sizeButton);boton7->setStyleSheet("QWidget {background-color:green}");
    boton8->move(745,320);boton8->setFixedSize(sizeButton);boton8->setStyleSheet("QWidget {background-color:green}");
    boton9->move(745,435);boton9->setFixedSize(sizeButton);boton9->setStyleSheet("QWidget {background-color:green}");
    boton10->move(745,550);boton10->setFixedSize(sizeButton);boton10->setStyleSheet("QWidget {background-color:green}");

    connect(boton0, SIGNAL (clicked()), this, SLOT(paginacion()));
    connect(boton11, SIGNAL (clicked()), this, SLOT(quitar()));

    ventana.show();
}
/**
 */
gMem::~gMem(){}