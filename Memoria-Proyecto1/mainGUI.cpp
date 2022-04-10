//
// Created by pablo on 18/3/22.
//
#include "mainGUI.h"

void mainGUI::faseTapeDestape(){
    if(tarjetasDestapadas.length() == limite_destape){
        destape = false;
        encontrarParejas();
    }
    if(tarjetasDestapadas.length()== 0){
        destape = true;
    }
}
void mainGUI::quitarEncontradas(int num){
    if(num == 0 ){boton0->close();}
    if(num == 1 ){boton1->close();}
    if(num == 2 ){boton2->close();}
    if(num == 3 ){boton3->close();}
    if(num == 4 ){boton4->close();}
    if(num == 5 ){boton5->close();}
    if(num == 6 ){boton6->close();}
    if(num == 7){boton7->close();}
}
void mainGUI::encontrarParejas(){
    if (tarjetas.value(tarjetasDestapadas.value(0))==tarjetas.value(tarjetasDestapadas.value(1))) {
        quitarEncontradas(tarjetasDestapadas.value(0));
        quitarEncontradas(tarjetasDestapadas.value(1));
        tarjetasDestapadas.clear();
        faseTapeDestape();
    }
}

void mainGUI::handleButton0(){
    if( destape ==  false){
        //destape = true;
        if (tarjetasDestapadas.contains(0)){

            boton0->setIcon(QIcon(QPixmap("Back-Card")));
            tarjetasDestapadas.removeAll(0);
            tarjetasTapadas.append(0);
            //cont_destape = cont_destape -1;
        }
    }
    else{

       QString FrontIMage = tarjetas.value(0);
       if (tarjetasTapadas.contains(0)){
           boton0->setIcon(QIcon(QPixmap(FrontIMage)));
            tarjetasTapadas.removeAll(0);
            tarjetasDestapadas.append(0);
           //cont_destape = cont_destape +1;
       }
    }
    this->faseTapeDestape();

}


void mainGUI::handleButton1(){
    //destroyed(QObject(encontradas.value(0)));
    //encontradas.value(0).close();
    //botones.value(0)->destroyed();
    if( destape ==  false){
        //destape = true;

        if (tarjetasDestapadas.contains(1)){

            boton1->setIcon(QIcon(QPixmap("Back-Card")));
            tarjetasDestapadas.removeAll(1);
            tarjetasTapadas.append(1);
            //cont_destape = cont_destape -1;
        }
    }
    else{
        //destape = false;
        QString FrontIMage = tarjetas.value(1);
        if (tarjetasTapadas.contains(1)){
            boton1->setIcon(QIcon(QPixmap(FrontIMage)));
            tarjetasTapadas.removeAll(1);
            tarjetasDestapadas.append(1);
            //cont_destape = cont_destape +1;
        }
    }
    this->faseTapeDestape();

}

void mainGUI::handleButton2(){
    if( destape ==  false){
        //destape = true;
        if (tarjetasDestapadas.contains(2)){

            boton2->setIcon(QIcon(QPixmap("Back-Card")));
            tarjetasDestapadas.removeAll(2);
            tarjetasTapadas.append(2);
            //cont_destape = cont_destape -1;
        }
    }
    else{

        QString FrontIMage = tarjetas.value(2);
        if (tarjetasTapadas.contains(2)){
            boton2->setIcon(QIcon(QPixmap(FrontIMage)));
            tarjetasTapadas.removeAll(2);
            tarjetasDestapadas.append(2);
            //cont_destape = cont_destape +1;
        }
    }
    this->faseTapeDestape();}

void mainGUI::handleButton3(){
    if( destape ==  false){
        //destape = true;
        if (tarjetasDestapadas.contains(3)){

            boton3->setIcon(QIcon(QPixmap("Back-Card")));
            tarjetasDestapadas.removeAll(3);
            tarjetasTapadas.append(3);
            //cont_destape = cont_destape -1;
        }
    }
    else{

        QString FrontIMage = tarjetas.value(3);
        if (tarjetasTapadas.contains(3)){
            boton3->setIcon(QIcon(QPixmap(FrontIMage)));
            tarjetasTapadas.removeAll(3);
            tarjetasDestapadas.append(3);
            //cont_destape = cont_destape +1;
        }
    }
    this->faseTapeDestape();}

void mainGUI::handleButton4(){
    if( destape ==  false){
        //destape = true;
        if (tarjetasDestapadas.contains(4)){

            boton4->setIcon(QIcon(QPixmap("Back-Card")));
            tarjetasDestapadas.removeAll(4);
            tarjetasTapadas.append(4);
            //cont_destape = cont_destape -1;
        }
    }
    else{

        QString FrontIMage = tarjetas.value(4);
        if (tarjetasTapadas.contains(4)){
            boton4->setIcon(QIcon(QPixmap(FrontIMage)));
            tarjetasTapadas.removeAll(4);
            tarjetasDestapadas.append(4);
            //cont_destape = cont_destape +1;
        }
    }
    this->faseTapeDestape();}

void mainGUI::handleButton5(){
    if( destape ==  false){
        //destape = true;
        if (tarjetasDestapadas.contains(5)){

            boton5->setIcon(QIcon(QPixmap("Back-Card")));
            tarjetasDestapadas.removeAll(5);
            tarjetasTapadas.append(5);
            //cont_destape = cont_destape -1;
        }
    }
    else{

        QString FrontIMage = tarjetas.value(5);
        if (tarjetasTapadas.contains(5)){
            boton5->setIcon(QIcon(QPixmap(FrontIMage)));
            tarjetasTapadas.removeAll(5);
            tarjetasDestapadas.append(5);
            //cont_destape = cont_destape +1;
        }
    }
    this->faseTapeDestape();}

void mainGUI::handleButton6(){
    if( destape ==  false){
        //destape = true;
        if (tarjetasDestapadas.contains(6)){

            boton6->setIcon(QIcon(QPixmap("Back-Card")));
            tarjetasDestapadas.removeAll(6);
            tarjetasTapadas.append(6);
            //cont_destape = cont_destape -1;
        }
    }
    else{

        QString FrontIMage = tarjetas.value(6);
        if (tarjetasTapadas.contains(6)){
            boton6->setIcon(QIcon(QPixmap(FrontIMage)));
            tarjetasTapadas.removeAll(6);
            tarjetasDestapadas.append(6);
            //cont_destape = cont_destape +1;
        }
    }
    this->faseTapeDestape();}

void mainGUI::handleButton7(){
    if( destape ==  false){
        //destape = true;
        if (tarjetasDestapadas.contains(7)){

            boton7->setIcon(QIcon(QPixmap("Back-Card")));
            tarjetasDestapadas.removeAll(7);
            tarjetasTapadas.append(7);
            //cont_destape = cont_destape -1;
        }
    }
    else{

        QString FrontIMage = tarjetas.value(7);
        if (tarjetasTapadas.contains(7)){
            boton7->setIcon(QIcon(QPixmap(FrontIMage)));
            tarjetasTapadas.removeAll(7);
            tarjetasDestapadas.append(7);
            //cont_destape = cont_destape +1;
        }
    }
    this->faseTapeDestape();}


mainGUI::mainGUI(QWidget *parent): QMainWindow(parent) {
    ventana.resize(800, 800);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Memoria");

    QPixmap backCardIMage("Back-Card.jpg");
    QIcon buttonIcon(backCardIMage);
    QSize sizeButton(95,100);
    //QSize sizeButton.setWidth(95);
    //QSize sizeButton.setHeight(100);

/**
 *
 *
 *     QSize * sizeButton = new QSize(95,100);
    QIcon * buttonIcon = new QIcon(QPixmap("Back-Card"));

    QIcon IconTest;
    QPixmap backCardIMage("Back-Card.jpg");
    buttonIcon(backCardIMage);

    IMage("Back-Card.jpg");
*/

    boton0->move(20,90);boton0->setFixedSize(sizeButton);
    boton0->setIcon(buttonIcon);boton0->setIconSize(backCardIMage.rect().size());

    boton1->move(135,90);boton1->setFixedSize(sizeButton);
    boton1->setIcon(buttonIcon);boton1->setIconSize(backCardIMage.rect().size());

    boton2->move(250,90);boton2->setFixedSize(sizeButton);
    boton2->setIcon(buttonIcon);boton2->setIconSize(backCardIMage.rect().size());

    boton3->move(365,90);boton3->setFixedSize(sizeButton);
    boton3->setIcon(buttonIcon);boton3->setIconSize(backCardIMage.rect().size());

    boton4->move(20,205);boton4->setFixedSize(sizeButton);
    boton4->setIcon(buttonIcon);boton4->setIconSize(backCardIMage.rect().size());

    boton5->move(135,205);boton5->setFixedSize(sizeButton);
    boton5->setIcon(buttonIcon);boton5->setIconSize(backCardIMage.rect().size());

    boton6->move(250,205);boton6->setFixedSize(sizeButton);
    boton6->setIcon(buttonIcon);boton6->setIconSize(backCardIMage.rect().size());

    boton7->move(365,205);boton7->setFixedSize(sizeButton);
    boton7->setIcon(buttonIcon);boton7->setIconSize(backCardIMage.rect().size());
    boton9->move(20,320);

    connect(boton0, SIGNAL (clicked()), this, SLOT(handleButton0()));
    connect(boton1, SIGNAL (pressed()), this, SLOT(handleButton1()));
    connect(boton2, SIGNAL (pressed()), this, SLOT(handleButton2()));
    connect(boton3, SIGNAL (pressed()), this, SLOT(handleButton3()));
    connect(boton4, SIGNAL (pressed()), this, SLOT(handleButton4()));
    connect(boton5, SIGNAL (pressed()), this, SLOT(handleButton5()));
    connect(boton6, SIGNAL (pressed()), this, SLOT(handleButton6()));
    connect(boton7, SIGNAL (pressed()), this, SLOT(handleButton7()));
    //encontradas.append(QPushButton(boton6));
    //encontradas.append(QVector <QPushButton> (botones));
    //encontradas.operator+({boton7,boton6});
    //botones.append(QPushButton({boton7}));
    ventana.show();
}

/**

 */
mainGUI::~mainGUI(){
    /**
    QIcon IconTest;

    */
}

