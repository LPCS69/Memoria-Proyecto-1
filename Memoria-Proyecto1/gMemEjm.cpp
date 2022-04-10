//
// Created by pablo on 8/4/22.
//

#include "gMemEjm.h"
void gMemEjm::cola_aleatoria(){
    int num;
    srand(time(NULL));

    while(enmemoria.length()<3) {
        num = rand() % 14;
        if (enmemoria.contains(num)==false){
            enmemoria.push_front(num);
        }
    }

}
void gMemEjm::cargar_nuevo(){
    int num;
    srand(time(NULL));
    num = rand() % 14;
    while(enmemoria.contains(num)== true){
        num = rand() % 14;
    }
    enmemoria.pop_back();
    enmemoria.push_front(num);
}
void gMemEjm::refrescar_botones(){
    // boton1->setText(tarjetas.value(enmemoria.value(0)));
    // boton2->setText(tarjetas.value(enmemoria.value(1)));
    // boton3->setText(tarjetas.value(enmemoria.value(2)));

    boton1->setStyleSheet(tarjetas.value(enmemoria.value(0)));
    boton2->setStyleSheet(tarjetas.value(enmemoria.value(1)));
    boton3->setStyleSheet(tarjetas.value(enmemoria.value(2)));
}
void gMemEjm::paginacion(){
    this->cargar_nuevo();
    this->refrescar_botones();
}

gMemEjm::gMemEjm(QWidget *parent): QMainWindow(parent) {
    ventana.resize(450, 450);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Gestion de Memoria");
    this->cola_aleatoria();
    //enmemoria.push_front(10);
    //enmemoria.push_front(11);
    //enmemoria.push_front(12);

    //QPixmap backCardIMage("Back-Card.jpg");
    //QIcon buttonIcon(backCardIMage);
    QSize sizeButton(95,100);

    boton0->move(20,90);boton0->setFixedSize(sizeButton);
    //boton0->setIcon(buttonIcon);boton0->setIconSize(backCardIMage.rect().size());
    boton0->setStyleSheet("QWidget {background-color:purple}");

    boton1->move(235,90);boton1->setFixedSize(sizeButton);
    //boton1->setIcon(buttonIcon);boton1->setIconSize(backCardIMage.rect().size());
    //boton1->setStyleSheet("QWidget {background-color:green}");
    //boton1->setText(tarjetas.value(enmemoria.value(0)));
    boton2->move(235,205);boton2->setFixedSize(sizeButton);
    //boton2->setIcon(buttonIcon);boton2->setIconSize(backCardIMage.rect().size());
    //boton2->setStyleSheet("QWidget {background-color:green}");
    //boton2->setText(tarjetas.value(enmemoria.value(1)));
    boton3->move(235,320);boton3->setFixedSize(sizeButton);
    //boton3->setStyleSheet("QWidget {background-color:green}");
    //boton3->setText(tarjetas.value(enmemoria.value(2)));
    //boton3->setIcon(buttonIcon);boton3->setIconSize(backCardIMage.rect().size());


    connect(boton0, SIGNAL (clicked()), this, SLOT(paginacion()));
    //connect(boton1, SIGNAL (pressed()), this, SLOT(handleButton1()));
    //connect(boton2, SIGNAL (pressed()), this, SLOT(handleButton2()));
    //connect(boton3, SIGNAL (pressed()), this, SLOT(handleButton3()));
    this->refrescar_botones();
    ventana.show();
}

/**

 */
gMemEjm::~gMemEjm(){

}