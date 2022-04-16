//
// Created by pablo on 10/4/22.
//

#include "clienteMem.h"

void clienteMem::Cliente(){
    server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    ::connect(server,(struct sockaddr *)&addr, sizeof(addr));
    memset(buffer, 0, sizeof(buffer));

}
void clienteMem::Enviar()
{
    //printf("Escribe el mensaje a enviar: ");
    //*buffer = NULL;
    std::string tmp = std::to_string(escogencia);
    char const *num_char = tmp.c_str();
    //std::stringstream temp = std::to_string(escogencia);
    //*mensaje = NULL;
    //*buffer = temp-> .c_str()
    strcat(strcpy(buffer, buffer),num_char );
    //memcpy(buffer,cadenaStd,cadenaStd.length());
    send(server, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    //memset(mensaje, 0, sizeof(mensaje));
    //printf("Mensaje enviado!");
}
void clienteMem::Recibir()
{
    recv(server, buffer, sizeof(buffer), 0);
    //mensaje = buffer[0];
    //strcat(strcpy(mensaje, buffer), "Hola Mal Parido");
    * mensaje =NULL;
    strcat(strcpy(mensaje, mensaje), buffer);
    eti->setText(QString(mensaje));

    memset(buffer, 0, sizeof(buffer));
}
void clienteMem::CerrarSocket()
{
    ::close(server);
    //WSACleanup();
    //printf("Socket cerrado.");
}
void clienteMem::posicion_aux(int num) {
    escogencia = num;
    label_escogencia->setText(QString::number(num));
}
void clienteMem::posicion0() {this->posicion_aux(0);}void clienteMem::posicion1() {this->posicion_aux(1);}
void clienteMem::posicion2() {this->posicion_aux(2);}void clienteMem::posicion3() {this->posicion_aux(3);}
void clienteMem::posicion4() {this->posicion_aux(4);}void clienteMem::posicion5() {this->posicion_aux(5);}
void clienteMem::posicion6() {this->posicion_aux(6);}void clienteMem::posicion7() {this->posicion_aux(7);}
void clienteMem::posicion8() {this->posicion_aux(8);}void clienteMem::posicion9() {this->posicion_aux(9);}

void clienteMem::posicion10() {this->posicion_aux(10);}void clienteMem::posicion11() {this->posicion_aux(11);}
void clienteMem::posicion12() {this->posicion_aux(12);}void clienteMem::posicion13() {this->posicion_aux(13);}
void clienteMem::posicion14() {this->posicion_aux(14);}void clienteMem::posicion15() {this->posicion_aux(15);}
void clienteMem::posicion16() {this->posicion_aux(16);}void clienteMem::posicion17() {this->posicion_aux(17);}
void clienteMem::posicion18() {this->posicion_aux(18);}void clienteMem::posicion19() {this->posicion_aux(19);}

void clienteMem::posicion20() {this->posicion_aux(20);}void clienteMem::posicion21() {this->posicion_aux(21);}
void clienteMem::posicion22() {this->posicion_aux(22);}void clienteMem::posicion23() {this->posicion_aux(23);}
void clienteMem::posicion24() {this->posicion_aux(24);}void clienteMem::posicion25() {this->posicion_aux(25);}
void clienteMem::posicion26() {this->posicion_aux(26);}void clienteMem::posicion27() {this->posicion_aux(27);}
void clienteMem::posicion28() {this->posicion_aux(28);}void clienteMem::posicion29() {this->posicion_aux(29);}

void clienteMem::posicion30() {this->posicion_aux(30);}void clienteMem::posicion31() {this->posicion_aux(31);}
void clienteMem::posicion32() {this->posicion_aux(32);}void clienteMem::posicion33() {this->posicion_aux(33);}
void clienteMem::posicion34() {this->posicion_aux(34);}void clienteMem::posicion35() {this->posicion_aux(35);}
void clienteMem::posicion36() {this->posicion_aux(36);}void clienteMem::posicion37() {this->posicion_aux(37);}
void clienteMem::posicion38() {this->posicion_aux(38);}void clienteMem::posicion39() {this->posicion_aux(39);}

void clienteMem::posicion40() {this->posicion_aux(40);}void clienteMem::posicion41() {this->posicion_aux(41);}
void clienteMem::posicion42() {this->posicion_aux(42);}void clienteMem::posicion43() {this->posicion_aux(43);}
void clienteMem::posicion44() {this->posicion_aux(44);}void clienteMem::posicion45() {this->posicion_aux(45);}
void clienteMem::posicion46() {this->posicion_aux(46);}void clienteMem::posicion47() {this->posicion_aux(47);}
void clienteMem::posicion48() {this->posicion_aux(48);}void clienteMem::posicion49() {this->posicion_aux(49);}

void clienteMem::posicion50() {this->posicion_aux(50);}void clienteMem::posicion51() {this->posicion_aux(51);}
void clienteMem::posicion52() {this->posicion_aux(52);}void clienteMem::posicion53() {this->posicion_aux(53);}
void clienteMem::posicion54() {this->posicion_aux(54);}void clienteMem::posicion55() {this->posicion_aux(55);}
void clienteMem::posicion56() {this->posicion_aux(56);}void clienteMem::posicion57() {this->posicion_aux(57);}
void clienteMem::posicion58() {this->posicion_aux(58);}void clienteMem::posicion59() {this->posicion_aux(59);}
clienteMem::clienteMem(QWidget *parent): QMainWindow(parent) {
    ventana.resize(1024, 720);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Memoria");

    QPixmap backCardIMage("Back-Card.jpg");
    QIcon buttonIcon(backCardIMage);
    QSize sizeButton(75,80);
/**
 * Estos son los objetos de la interfaz encargada de manejar la comunicación entre sockets
 */
    QSize sizeButton2(85,25);
    b_enviar->move(20, 610);
    b_enviar->setFixedSize(sizeButton2);
    b_enviar->setStyleSheet("QWidget {background-color:green}");

    b_recibir->move(20, 640);
    b_recibir->setFixedSize(sizeButton2);
    b_recibir->setStyleSheet("QWidget {background-color:gold}");

    b_conectar->move(20, 670);
    b_conectar->setFixedSize(sizeButton2);
    b_conectar->setStyleSheet("QWidget {background-color:navy}");

    eti->move(120, 640);
    const char *str1 = "QWidget {background-color:gold}";
    eti->setStyleSheet(str1);
    eti->setFixedSize(45, 20);

    label_escogencia->move(320, 640);
    label_escogencia->setStyleSheet("QWidget {background-color:navy}");
    label_escogencia->setFixedSize(45, 20);

    cb_sockets->setFixedSize(45, 20);
    cb_sockets->move(120, 610);
    cb_sockets->setStyleSheet("QWidget {border: 1px solid white}");
    cb_sockets->setStyleSheet("QWidget {background-color:purple}");
    cb_sockets->addItem("A");
    cb_sockets->addItem("B");
    cb_sockets->addItem("C");
    cb_sockets->addItem("D");
    cb_sockets->addItem("E");
    cb_sockets->addItem("F");
    cb_sockets->addItem("G");
    connect( b_enviar, SIGNAL (clicked()), this, SLOT(Enviar()));
    connect(b_recibir, SIGNAL (clicked()), this, SLOT(Recibir()));
    connect(b_conectar, SIGNAL (clicked()), this, SLOT(Cliente()));
/**
 * FILA1   FILA1   FILA1   FILA1   FILA1   FILA1   FILA1   FILA1   FILA1
 */
    boton0->move(20,20);boton0->setFixedSize(sizeButton);
    //boton0->setIcon(buttonIcon);boton0->setIconSize(backCardIMage.rect().size());

    boton1->move(120,20);boton1->setFixedSize(sizeButton);
    //boton1->setIcon(buttonIcon);boton1->setIconSize(backCardIMage.rect().size());

    boton2->move(220,20);boton2->setFixedSize(sizeButton);
    //boton2->setIcon(buttonIcon);boton2->setIconSize(backCardIMage.rect().size());

    boton3->move(320,20);boton3->setFixedSize(sizeButton);
    //boton3->setIcon(buttonIcon);boton3->setIconSize(backCardIMage.rect().size());

    boton4->move(420,20);boton4->setFixedSize(sizeButton);
    //boton4->setIcon(buttonIcon);boton4->setIconSize(backCardIMage.rect().size());

    boton5->move(520,20);boton5->setFixedSize(sizeButton);
    //boton5->setIcon(buttonIcon);boton5->setIconSize(backCardIMage.rect().size());

    boton6->move(620,20);boton6->setFixedSize(sizeButton);
    //boton6->setIcon(buttonIcon);boton6->setIconSize(backCardIMage.rect().size());

    boton7->move(720,20);boton7->setFixedSize(sizeButton);
    //boton7->setIcon(buttonIcon);boton7->setIconSize(backCardIMage.rect().size());

    boton8->move(820,20);boton8->setFixedSize(sizeButton);
    //boton8->setIcon(buttonIcon);boton8->setIconSize(backCardIMage.rect().size());

    boton9->move(920,20);boton9->setFixedSize(sizeButton);
    //boton9->setIcon(buttonIcon);boton9->setIconSize(backCardIMage.rect().size());
/**
 * FILA2   FILA2   FILA2   FILA2   FILA2   FILA2   FILA2   FILA2   FILA2
 */


    boton10->move(20,120);boton10->setFixedSize(sizeButton);
    //boton10->setIcon(buttonIcon);boton10->setIconSize(backCardIMage.rect().size());

    boton11->move(120,120);boton11->setFixedSize(sizeButton);
    //boton11->setIcon(buttonIcon);boton11->setIconSize(backCardIMage.rect().size());

    boton12->move(220,120);boton12->setFixedSize(sizeButton);
    //boton12->setIcon(buttonIcon);boton12->setIconSize(backCardIMage.rect().size());

    boton13->move(320,120);boton13->setFixedSize(sizeButton);
    //boton13->setIcon(buttonIcon);boton13->setIconSize(backCardIMage.rect().size());

    boton14->move(420,120);boton14->setFixedSize(sizeButton);
    //boton14->setIcon(buttonIcon);boton14->setIconSize(backCardIMage.rect().size());

    boton15->move(520,120);boton15->setFixedSize(sizeButton);
    //boton15->setIcon(buttonIcon);boton15->setIconSize(backCardIMage.rect().size());

    boton16->move(620,120);boton16->setFixedSize(sizeButton);
    //boton16->setIcon(buttonIcon);boton16->setIconSize(backCardIMage.rect().size());

    boton17->move(720,120);boton17->setFixedSize(sizeButton);
    //boton17->setIcon(buttonIcon);boton17->setIconSize(backCardIMage.rect().size());

    boton18->move(820,120);boton18->setFixedSize(sizeButton);
    //boton18->setIcon(buttonIcon);boton18->setIconSize(backCardIMage.rect().size());

    boton19->move(920,120);boton19->setFixedSize(sizeButton);
    //boton19->setIcon(buttonIcon);boton19->setIconSize(backCardIMage.rect().size());
/**
 * FILA3   FILA3   FILA3   FILA3   FILA3   FILA3   FILA3   FILA3   FILA3
 */
    boton20->move(20,220);boton20->setFixedSize(sizeButton);
    //boton20->setIcon(buttonIcon);boton20->setIconSize(backCardIMage.rect().size());

    boton21->move(120,220);boton21->setFixedSize(sizeButton);
    //boton21->setIcon(buttonIcon);boton21->setIconSize(backCardIMage.rect().size());

    boton22->move(220,220);boton22->setFixedSize(sizeButton);
    //boton22->setIcon(buttonIcon);boton22->setIconSize(backCardIMage.rect().size());

    boton23->move(320,220);boton23->setFixedSize(sizeButton);
    //boton23->setIcon(buttonIcon);boton23->setIconSize(backCardIMage.rect().size());

    boton24->move(420,220);boton24->setFixedSize(sizeButton);
    //boton24->setIcon(buttonIcon);boton24->setIconSize(backCardIMage.rect().size());

    boton25->move(520,220);boton25->setFixedSize(sizeButton);
    //boton25->setIcon(buttonIcon);boton25->setIconSize(backCardIMage.rect().size());

    boton26->move(620,220);boton26->setFixedSize(sizeButton);
    //boton26->setIcon(buttonIcon);boton26->setIconSize(backCardIMage.rect().size());

    boton27->move(720,220);boton27->setFixedSize(sizeButton);
    //boton27->setIcon(buttonIcon);boton27->setIconSize(backCardIMage.rect().size());

    boton28->move(820,220);boton28->setFixedSize(sizeButton);
    //boton28->setIcon(buttonIcon);boton28->setIconSize(backCardIMage.rect().size());

    boton29->move(920,220);boton29->setFixedSize(sizeButton);
    //boton29->setIcon(buttonIcon);boton29->setIconSize(backCardIMage.rect().size());
/**
* FILA4   FILA4   FILA4   FILA4   FILA4   FILA4   FILA4   FILA4   FILA4
*/
    boton30->move(20,320);boton30->setFixedSize(sizeButton);
    //boton30->setIcon(buttonIcon);boton30->setIconSize(backCardIMage.rect().size());

    boton31->move(120,320);boton31->setFixedSize(sizeButton);
    //boton31->setIcon(buttonIcon);boton31->setIconSize(backCardIMage.rect().size());

    boton32->move(220,320);boton32->setFixedSize(sizeButton);
    //boton32->setIcon(buttonIcon);boton32->setIconSize(backCardIMage.rect().size());

    boton33->move(320,320);boton33->setFixedSize(sizeButton);
    //boton33->setIcon(buttonIcon);boton33->setIconSize(backCardIMage.rect().size());

    boton34->move(420,320);boton34->setFixedSize(sizeButton);
    //boton34->setIcon(buttonIcon);boton34->setIconSize(backCardIMage.rect().size());

    boton35->move(520,320);boton35->setFixedSize(sizeButton);
    //boton35->setIcon(buttonIcon);boton35->setIconSize(backCardIMage.rect().size());

    boton36->move(620,320);boton36->setFixedSize(sizeButton);
    //boton26->setIcon(buttonIcon);boton26->setIconSize(backCardIMage.rect().size());

    boton37->move(720,320);boton37->setFixedSize(sizeButton);
    //boton27->setIcon(buttonIcon);boton27->setIconSize(backCardIMage.rect().size());

    boton38->move(820,320);boton38->setFixedSize(sizeButton);
    //boton28->setIcon(buttonIcon);boton28->setIconSize(backCardIMage.rect().size());

    boton39->move(920,320);boton39->setFixedSize(sizeButton);
    //boton29->setIcon(buttonIcon);boton29->setIconSize(backCardIMage.rect().size());
/**
* FILA5   FILA5   FILA5   FILA5   FILA5   FILA5   FILA5   FILA5   FILA5
*/
    boton40->move(20,420);boton40->setFixedSize(sizeButton);
    //boton30->setIcon(buttonIcon);boton30->setIconSize(backCardIMage.rect().size());

    boton41->move(120,420);boton41->setFixedSize(sizeButton);
    //boton31->setIcon(buttonIcon);boton31->setIconSize(backCardIMage.rect().size());

    boton42->move(220,420);boton42->setFixedSize(sizeButton);
    //boton32->setIcon(buttonIcon);boton32->setIconSize(backCardIMage.rect().size());

    boton43->move(320,420);boton43->setFixedSize(sizeButton);
    //boton33->setIcon(buttonIcon);boton33->setIconSize(backCardIMage.rect().size());

    boton44->move(420,420);boton44->setFixedSize(sizeButton);
    //boton34->setIcon(buttonIcon);boton34->setIconSize(backCardIMage.rect().size());

    boton45->move(520,420);boton45->setFixedSize(sizeButton);
    //boton35->setIcon(buttonIcon);boton35->setIconSize(backCardIMage.rect().size());

    boton46->move(620,420);boton46->setFixedSize(sizeButton);
    //boton26->setIcon(buttonIcon);boton26->setIconSize(backCardIMage.rect().size());

    boton47->move(720,420);boton47->setFixedSize(sizeButton);
    //boton27->setIcon(buttonIcon);boton27->setIconSize(backCardIMage.rect().size());

    boton48->move(820,420);boton48->setFixedSize(sizeButton);
    //boton28->setIcon(buttonIcon);boton28->setIconSize(backCardIMage.rect().size());

    boton49->move(920,420);boton49->setFixedSize(sizeButton);
    //boton29->setIcon(buttonIcon);boton29->setIconSize(backCardIMage.rect().size());

/**
* FILA6   FILA6   FILA6   FILA6   FILA6   FILA6   FILA6   FILA6   FILA6
*/
    boton50->move(20,520);boton50->setFixedSize(sizeButton);
    //boton30->setIcon(buttonIcon);boton30->setIconSize(backCardIMage.rect().size());

    boton51->move(120,520);boton51->setFixedSize(sizeButton);
    //boton31->setIcon(buttonIcon);boton31->setIconSize(backCardIMage.rect().size());

    boton52->move(220,520);boton52->setFixedSize(sizeButton);
    //boton32->setIcon(buttonIcon);boton32->setIconSize(backCardIMage.rect().size());

    boton53->move(320,520);boton53->setFixedSize(sizeButton);
    //boton33->setIcon(buttonIcon);boton33->setIconSize(backCardIMage.rect().size());

    boton54->move(420,520);boton54->setFixedSize(sizeButton);
    //boton34->setIcon(buttonIcon);boton34->setIconSize(backCardIMage.rect().size());

    boton55->move(520,520);boton55->setFixedSize(sizeButton);
    //boton35->setIcon(buttonIcon);boton35->setIconSize(backCardIMage.rect().size());

    boton56->move(620,520);boton56->setFixedSize(sizeButton);
    //boton26->setIcon(buttonIcon);boton26->setIconSize(backCardIMage.rect().size());

    boton57->move(720,520);boton57->setFixedSize(sizeButton);
    //boton27->setIcon(buttonIcon);boton27->setIconSize(backCardIMage.rect().size());

    boton58->move(820,520);boton58->setFixedSize(sizeButton);
    //boton28->setIcon(buttonIcon);boton28->setIconSize(backCardIMage.rect().size());

    boton59->move(920,520);boton59->setFixedSize(sizeButton);
    //boton29->setIcon(buttonIcon);boton29->setIconSize(backCardIMage.rect().size());
    boton0->setStyleSheet("QWidget  {background-color:white}");boton1->setStyleSheet("QWidget  {background-color:white}");
    boton2->setStyleSheet("QWidget  {background-color:white}");boton3->setStyleSheet("QWidget  {background-color:white}");
    boton4->setStyleSheet("QWidget  {background-color:white}");boton5->setStyleSheet("QWidget  {background-color:white}");
    boton6->setStyleSheet("QWidget  {background-color:white}");boton7->setStyleSheet("QWidget  {background-color:white}");
    boton8->setStyleSheet("QWidget  {background-color:white}");boton9->setStyleSheet("QWidget  {background-color:white}");
    boton10->setStyleSheet("QWidget {background-color:white}");boton11->setStyleSheet("QWidget {background-color:white}");
    boton12->setStyleSheet("QWidget {background-color:white}");boton13->setStyleSheet("QWidget {background-color:white}");
    boton14->setStyleSheet("QWidget {background-color:white}");boton15->setStyleSheet("QWidget {background-color:white}");
    boton16->setStyleSheet("QWidget {background-color:white}");boton17->setStyleSheet("QWidget {background-color:white}");
    boton18->setStyleSheet("QWidget {background-color:white}");boton19->setStyleSheet("QWidget {background-color:white}");
    boton20->setStyleSheet("QWidget {background-color:white}");boton21->setStyleSheet("QWidget {background-color:white}");
    boton22->setStyleSheet("QWidget {background-color:white}");boton23->setStyleSheet("QWidget {background-color:white}");
    boton24->setStyleSheet("QWidget {background-color:white}");boton25->setStyleSheet("QWidget {background-color:white}");
    boton26->setStyleSheet("QWidget {background-color:white}");boton27->setStyleSheet("QWidget {background-color:white}");
    boton28->setStyleSheet("QWidget {background-color:white}");boton29->setStyleSheet("QWidget {background-color:white}");
    boton30->setStyleSheet("QWidget {background-color:white}");boton31->setStyleSheet("QWidget {background-color:white}");
    boton32->setStyleSheet("QWidget {background-color:white}");boton33->setStyleSheet("QWidget {background-color:white}");
    boton34->setStyleSheet("QWidget {background-color:white}");boton35->setStyleSheet("QWidget {background-color:white}");
    boton36->setStyleSheet("QWidget {background-color:white}");boton37->setStyleSheet("QWidget {background-color:white}");
    boton38->setStyleSheet("QWidget {background-color:white}");boton39->setStyleSheet("QWidget {background-color:white}");
    boton40->setStyleSheet("QWidget {background-color:white}");boton41->setStyleSheet("QWidget {background-color:white}");
    boton42->setStyleSheet("QWidget {background-color:white}");boton43->setStyleSheet("QWidget {background-color:white}");
    boton44->setStyleSheet("QWidget {background-color:white}");boton45->setStyleSheet("QWidget {background-color:white}");
    boton46->setStyleSheet("QWidget {background-color:white}");boton47->setStyleSheet("QWidget {background-color:white}");
    boton48->setStyleSheet("QWidget {background-color:white}");boton49->setStyleSheet("QWidget {background-color:white}");
    boton50->setStyleSheet("QWidget {background-color:white}");boton51->setStyleSheet("QWidget {background-color:white}");
    boton52->setStyleSheet("QWidget {background-color:white}");boton53->setStyleSheet("QWidget {background-color:white}");
    boton54->setStyleSheet("QWidget {background-color:white}");boton55->setStyleSheet("QWidget {background-color:white}");
    boton56->setStyleSheet("QWidget {background-color:white}");boton57->setStyleSheet("QWidget {background-color:white}");
    boton58->setStyleSheet("QWidget {background-color:white}");boton59->setStyleSheet("QWidget {background-color:white}");

    connect(boton0, SIGNAL (clicked()), this, SLOT(posicion0()));
    connect(boton1, SIGNAL (clicked()), this, SLOT(posicion1()));
    connect(boton2, SIGNAL (clicked()), this, SLOT(posicion2()));
    connect(boton3, SIGNAL (clicked()), this, SLOT(posicion3()));
    connect(boton4, SIGNAL (clicked()), this, SLOT(posicion4()));
    connect(boton5, SIGNAL (clicked()), this, SLOT(posicion5()));
    connect(boton6, SIGNAL (clicked()), this, SLOT(posicion6()));
    connect(boton7, SIGNAL (clicked()), this, SLOT(posicion7()));
    connect(boton8, SIGNAL (clicked()), this, SLOT(posicion8()));
    connect(boton9, SIGNAL (clicked()), this, SLOT(posicion9()));

    connect(boton10, SIGNAL (clicked()), this, SLOT(posicion10()));
    connect(boton11, SIGNAL (clicked()), this, SLOT(posicion11()));
    connect(boton12, SIGNAL (clicked()), this, SLOT(posicion12()));
    connect(boton13, SIGNAL (clicked()), this, SLOT(posicion13()));
    connect(boton14, SIGNAL (clicked()), this, SLOT(posicion14()));
    connect(boton15, SIGNAL (clicked()), this, SLOT(posicion15()));
    connect(boton16, SIGNAL (clicked()), this, SLOT(posicion16()));
    connect(boton17, SIGNAL (clicked()), this, SLOT(posicion17()));
    connect(boton18, SIGNAL (clicked()), this, SLOT(posicion18()));
    connect(boton19, SIGNAL (clicked()), this, SLOT(posicion19()));

    connect(boton20, SIGNAL (clicked()), this, SLOT(posicion20()));
    connect(boton21, SIGNAL (clicked()), this, SLOT(posicion21()));
    connect(boton22, SIGNAL (clicked()), this, SLOT(posicion22()));
    connect(boton23, SIGNAL (clicked()), this, SLOT(posicion23()));
    connect(boton24, SIGNAL (clicked()), this, SLOT(posicion24()));
    connect(boton25, SIGNAL (clicked()), this, SLOT(posicion25()));
    connect(boton26, SIGNAL (clicked()), this, SLOT(posicion26()));
    connect(boton27, SIGNAL (clicked()), this, SLOT(posicion27()));
    connect(boton28, SIGNAL (clicked()), this, SLOT(posicion28()));
    connect(boton29, SIGNAL (clicked()), this, SLOT(posicion29()));

    connect(boton30, SIGNAL (clicked()), this, SLOT(posicion30()));
    connect(boton31, SIGNAL (clicked()), this, SLOT(posicion31()));
    connect(boton32, SIGNAL (clicked()), this, SLOT(posicion32()));
    connect(boton33, SIGNAL (clicked()), this, SLOT(posicion33()));
    connect(boton34, SIGNAL (clicked()), this, SLOT(posicion34()));
    connect(boton35, SIGNAL (clicked()), this, SLOT(posicion35()));
    connect(boton36, SIGNAL (clicked()), this, SLOT(posicion36()));
    connect(boton37, SIGNAL (clicked()), this, SLOT(posicion37()));
    connect(boton38, SIGNAL (clicked()), this, SLOT(posicion38()));
    connect(boton39, SIGNAL (clicked()), this, SLOT(posicion39()));

    connect(boton40, SIGNAL (clicked()), this, SLOT(posicion40()));
    connect(boton41, SIGNAL (clicked()), this, SLOT(posicion41()));
    connect(boton42, SIGNAL (clicked()), this, SLOT(posicion42()));
    connect(boton43, SIGNAL (clicked()), this, SLOT(posicion43()));
    connect(boton44, SIGNAL (clicked()), this, SLOT(posicion44()));
    connect(boton45, SIGNAL (clicked()), this, SLOT(posicion45()));
    connect(boton46, SIGNAL (clicked()), this, SLOT(posicion46()));
    connect(boton47, SIGNAL (clicked()), this, SLOT(posicion47()));
    connect(boton48, SIGNAL (clicked()), this, SLOT(posicion48()));
    connect(boton49, SIGNAL (clicked()), this, SLOT(posicion49()));

    connect(boton50, SIGNAL (clicked()), this, SLOT(posicion50()));
    connect(boton51, SIGNAL (clicked()), this, SLOT(posicion51()));
    connect(boton52, SIGNAL (clicked()), this, SLOT(posicion52()));
    connect(boton53, SIGNAL (clicked()), this, SLOT(posicion53()));
    connect(boton54, SIGNAL (clicked()), this, SLOT(posicion54()));
    connect(boton55, SIGNAL (clicked()), this, SLOT(posicion55()));
    connect(boton56, SIGNAL (clicked()), this, SLOT(posicion56()));
    connect(boton57, SIGNAL (clicked()), this, SLOT(posicion57()));
    connect(boton58, SIGNAL (clicked()), this, SLOT(posicion58()));
    connect(boton59, SIGNAL (clicked()), this, SLOT(posicion59()));
/**
    connect(boton0, SIGNAL (clicked()), this, SLOT(handleButton0()));
    connect(boton1, SIGNAL (pressed()), this, SLOT(handleButton1()));
    connect(boton2, SIGNAL (pressed()), this, SLOT(handleButton2()));
    connect(boton3, SIGNAL (pressed()), this, SLOT(handleButton3()));
    connect(boton4, SIGNAL (pressed()), this, SLOT(handleButton4()));
    connect(boton5, SIGNAL (pressed()), this, SLOT(handleButton5()));
    connect(boton6, SIGNAL (pressed()), this, SLOT(handleButton6()));
    connect(boton7, SIGNAL (pressed()), this, SLOT(handleButton7()));
*/
    ventana.show();
}

/**

 */
clienteMem::~clienteMem() {

}