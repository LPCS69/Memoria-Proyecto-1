//
// Created by pablo on 8/4/22.
//

#include "gMem.h"
void gMem::mostrar_variables_enDisco() {
    int cont = 0;
    //if(!enmemoria.empty()){
    while (cont < tarjetas.length()){
        if (!enmemoria.contains(cont)){
            sin_cargar = sin_cargar + tarjetas.value(cont);
        }
        cont++;
    }
    //}
}
void gMem::cola_aleatoria(){
    int num;
    srand(time(NULL));

    while(enmemoria.length()<espacio_enmemoria) {
        num = rand() % tarjetas.length();
        if (enmemoria.contains(num)==false){
            enmemoria.push_front(num);
        }
    }

}
void gMem::cargar_nuevo(){
    int num;
    srand(time(NULL));
    num = rand() % tarjetas.length();
    while(enmemoria.contains(num)== true){
        num = rand() % tarjetas.length();
    }
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



    if(espacio_enmemoria > 1){
        boton2->setText(tarjetas.value(enmemoria.value(1)));
    }
    if(espacio_enmemoria > 2){
        boton3->setText(tarjetas.value(enmemoria.value(2)));
    }
    if (espacio_enmemoria > 3){
        boton4->setText(tarjetas.value(enmemoria.value(3)));
    }
    if (espacio_enmemoria > 4){
        boton5->setText(tarjetas.value(enmemoria.value(4)));
    }
    if (espacio_enmemoria > 5){
        boton6->setText(tarjetas.value(enmemoria.value(5)));
    }
    if (espacio_enmemoria > 6){
        boton7->setText(tarjetas.value(enmemoria.value(6)));
    }
    if (espacio_enmemoria > 7){
        boton8->setText(tarjetas.value(enmemoria.value(7)));
    }
    if (espacio_enmemoria > 8){
        boton9->setText(tarjetas.value(enmemoria.value(8)));
    }
    if (espacio_enmemoria > 9){
        boton10->setText(tarjetas.value(enmemoria.value(9)));
    }
}
void gMem::paginacion(){
    if(enmemoria.empty()){
        this->cola_aleatoria();
    }
    else{
    this->cargar_nuevo();
    }
    this->refrescar_botones();

}

void gMem::quitar(){
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
    }
};

gMem::gMem(QWidget *parent): QMainWindow(parent) {
    ventana.resize(600, 800);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Gestion de Memoria");
    espacio_enmemoria = tarjetas.length()/3;
    //QString str = "*";
    label_espacio->setText(QString(QString::number(espacio_enmemoria)));
    label_espacio->setFixedSize(95,30);
    label_espacio->move(20,680);
    label_espacio->setStyleSheet("QWidget {background-color:red}");

    label_enDisco->setText(sin_cargar);
    label_enDisco->setFixedSize(450,30);
    label_enDisco->move(20,725);
    label_enDisco->setStyleSheet("QWidget {background-color:blue}");
    //this->cola_aleatoria();
    //this->refrescar_botones();
    //enmemoria.push_front(10);
    //enmemoria.push_front(11);
    //enmemoria.push_front(12);

    //QPixmap backCardIMage("Back-Card.jpg");
    //QIcon buttonIcon(backCardIMage);
    QSize sizeButton(95,100);

    boton0->move(20,435);boton0->setFixedSize(sizeButton);
    //boton0->setIcon(buttonIcon);boton0->setIconSize(backCardIMage.rect().size());
    boton0->setStyleSheet("QWidget {background-color:purple}");

    boton11->move(20,550 );boton11->setFixedSize(sizeButton);
    //boton0->setIcon(buttonIcon);boton0->setIconSize(backCardIMage.rect().size());
    boton11->setStyleSheet("QWidget {background-color:yellow}");

    boton1->move(235,90);boton1->setFixedSize(sizeButton);
    //boton1->setIcon(buttonIcon);boton1->setIconSize(backCardIMage.rect().size());
    boton1->setStyleSheet("QWidget {background-color:green}");
    //boton1->setText(tarjetas.value(enmemoria.value(0)));
    boton2->move(235,205);boton2->setFixedSize(sizeButton);
    //boton2->setIcon(buttonIcon);boton2->setIconSize(backCardIMage.rect().size());
    boton2->setStyleSheet("QWidget {background-color:green}");
    //boton2->setText(tarjetas.value(enmemoria.value(1)));
    boton3->move(235,320);boton3->setFixedSize(sizeButton);
    boton3->setStyleSheet("QWidget {background-color:green}");
    //boton3->setText(tarjetas.value(enmemoria.value(2)));
    //boton3->setIcon(buttonIcon);boton3->setIconSize(backCardIMage.rect().size());

    boton4->move(235,435);boton4->setFixedSize(sizeButton);
    boton4->setStyleSheet("QWidget {background-color:green}");

    boton5->move(235,550);boton5->setFixedSize(sizeButton);
    boton5->setStyleSheet("QWidget {background-color:green}");

    boton6->move(450,90);boton6->setFixedSize(sizeButton);
    boton6->setStyleSheet("QWidget {background-color:green}");

    boton7->move(450,205);boton7->setFixedSize(sizeButton);
    boton7->setStyleSheet("QWidget {background-color:green}");

    boton8->move(450,320);boton8->setFixedSize(sizeButton);
    boton8->setStyleSheet("QWidget {background-color:green}");

    boton9->move(450,435);boton9->setFixedSize(sizeButton);
    boton9->setStyleSheet("QWidget {background-color:green}");

    boton10->move(450,550);boton10->setFixedSize(sizeButton);
    boton10->setStyleSheet("QWidget {background-color:green}");

    connect(boton0, SIGNAL (clicked()), this, SLOT(paginacion()));
    connect(boton11, SIGNAL (clicked()), this, SLOT(quitar()));
    //connect(boton1, SIGNAL (pressed()), this, SLOT(handleButton1()));
    //connect(boton2, SIGNAL (pressed()), this, SLOT(handleButton2()));
    //connect(boton3, SIGNAL (pressed()), this, SLOT(handleButton3()));
    //this->refrescar_botones();
    ventana.show();
}

/**

 */
gMem::~gMem(){

}