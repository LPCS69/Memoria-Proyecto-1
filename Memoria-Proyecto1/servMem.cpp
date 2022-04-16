//
// Created by pablo on 8/4/22.
//

#include "servMem.h"
/**
 * Este metodo se encarga de asignar a una variabnle los datos que no se han cargado en memoria y mostrarlos
 * en una etiqueta.
 */

class tarjeta: public QObject{
private:
    QString imagen;
    QString pos_A;
    QString pos_B;
    int campo_enmemoria;
public:
    tarjeta();
    void set_posiciones(QVector <QString>);
    void set_imagen(QString);
    void set_campoenmemoria(int);
    QString get_posA();
    QString get_posB();
    QString get_Imagen();
    int get_CampoenMemoria();
};
tarjeta::tarjeta() {
    pos_A = "XXXX";
    pos_B = "XXXX";
    imagen = "VACIO";
}
void tarjeta::set_posiciones(QVector <QString> pos) {
    pos_A = pos.value(0);
    pos_B = pos.value(1);
}
void tarjeta::set_imagen(QString im) {imagen = im;}
void tarjeta::set_campoenmemoria(int num) {campo_enmemoria = num;}
QString tarjeta::get_posA(){return pos_A;}
QString tarjeta::get_posB(){return pos_B;}
QString tarjeta::get_Imagen(){return imagen;}
int tarjeta::get_CampoenMemoria(){return campo_enmemoria;}

void servMem::mostrar_variables_enDisco() {
    int cont = 0;
    sin_cargar = "";
    if(enmemoria.empty()){
    while (cont < tarjetas.length()){
            sin_cargar = sin_cargar + "|" + tarjetas.value(cont) + "\n";
            cb->addItem(tarjetas.value(cont));
            cont++;
    }
    }
    else{
        while (cont < tarjetas.length()){
            if (!enmemoria.contains(cont)){
            sin_cargar = sin_cargar + "|" + tarjetas.value(cont)+ "\n";
            }
            cont++;
        }
    }
    label_enDisco->setText(sin_cargar+"|"+"ext:"+ "\n"+"|"+QString::number(tarjetas.length()));
}
/**
 * Este metodo se encarga de mostrar las posiciones de la martiz del juego que se le han asignado a cada imagen
 *
 */
void servMem::mostrar_posiciones_asignadas()  {
    int cont = 0;
    posiciones_asignadas = "";
        while (cont < posiciones_barajadas.length()){
            posiciones_asignadas = posiciones_asignadas + " "+ posiciones_barajadas.value(cont)+
                    " - " + posiciones_barajadas.value(cont+1)+ "\n";
            cont= cont + 2;
        }

    label_posiciones->setText(posiciones_asignadas+"|"+"ext:"+ "\n"+"|"+QString::number(tarjetas.length()));
}

/**
 * Este metodo se encarga cargar las referencias de las posiciones del vector que almacena los vectores de las
 * posiciones que han sido asignadas a cada imagen
 *
 */

void servMem::referencias_posiciones(){
    int cont = 0;
    while (cont < 30){
        cb_posiciones->addItem(tarjetas.value(cont));
        cont++;
    }
}
void servMem::referencias_busqueda(){
    int cont = 0;
    while (cont < 60){
        cb_buscar->addItem(posiciones.value(cont));
        cont++;
    }
}
/**
 * Este metodo se encarga de mostrar las posiciones de la martiz del juego que se le han asignado a cada imagen
 *
 */
void servMem::mostrar_posiciones()  {
    QString str;
    QVector <QString>temp;
    temp = posiciones_imagenes.value(cb_posiciones->currentIndex());
    str = temp.value(0)+ " - "+temp.value(1);
    label_referencias->setText(str);
}
/**
 * Este metodo llena con valores escogidos de forma aleatoria la Cola que simula ser la memoria virtual
 * teniendo de limite la cantidad preestableciada para el tamaño de esta
 */
void servMem::cola_aleatoria(){
    int num;
    srand(time(NULL));

    while(enmemoria.length()<espacio_enmemoria) {
        num = rand() % tarjetas.length();
        if (enmemoria.contains(num)==false){
            enmemoria.push_front(num);}
    }
}
void servMem::barajar() {
    int num;
    srand(time(NULL));

    while(posiciones_barajadas.length()<posiciones.length()) {
        num = rand() % posiciones.length();
        if (posiciones_barajadas.contains(posiciones.value(num))==false){
            posiciones_barajadas.push_front(posiciones.value(num));}
    }
}
void servMem::cortar_baraja() {
    QVector <QString> vector_temp;
    int cont = 0;
    while (cont < posiciones_barajadas.length()){
        vector_temp.push_back(posiciones_barajadas.value(cont));
        vector_temp.push_back(posiciones_barajadas.value(cont+1));
        posiciones_imagenes.push_back(vector_temp);
        vector_temp.pop_back();
        vector_temp.pop_back();
        cont = cont +2;

    }

}

void servMem::cargar_datos_enmemoria(){
    if(!enmemoria.contains(seleccion)){
    enmemoria.push_front(seleccion);}
};

void servMem::buscar_imagen() {
    int cont = 0;
    while (!posiciones_imagenes.value(cont).contains(cb_buscar->currentText())){
        cont++;
    }
    seleccion = cont;
    label_busqueda->setText(tarjetas.value(cont));
    this->paginacion();
}

/**
void servMem::remplazo_aleatorio(){
    int num;
    srand(time(NULL));
    num = rand() % tarjetas.length();
    while(enmemoria.contains(num)== true){
        num = rand() % tarjetas.length();}
    enmemoria.pop_back();
    enmemoria.push_front(num);
}
*/
void servMem::remplazo(){
    if(!enmemoria.contains(seleccion)){
    enmemoria.pop_back();
    enmemoria.push_front(seleccion);
    }
}
void servMem::cargar_espacios_libres(){
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

void servMem::refrescar_botones(){
    boton1->setText(tarjetas.value(enmemoria.value(0)));
    if(espacio_enmemoria > 1  & enmemoria.length()>1){boton2->setText(tarjetas.value(enmemoria.value(1)));}
    if(espacio_enmemoria > 2  & enmemoria.length()>2){boton3->setText(tarjetas.value(enmemoria.value(2)));}
    if (espacio_enmemoria > 3 & enmemoria.length()>3){boton4->setText(tarjetas.value(enmemoria.value(3)));}
    if (espacio_enmemoria > 4 & enmemoria.length()>4){boton5->setText(tarjetas.value(enmemoria.value(4)));}
    if (espacio_enmemoria > 5 & enmemoria.length()>5){boton6->setText(tarjetas.value(enmemoria.value(5)));}
    if (espacio_enmemoria > 6 & enmemoria.length()>6){boton7->setText(tarjetas.value(enmemoria.value(6)));}
    if (espacio_enmemoria > 7 & enmemoria.length()>7){boton8->setText(tarjetas.value(enmemoria.value(7)));}
    if (espacio_enmemoria > 8 & enmemoria.length()>8){boton9->setText(tarjetas.value(enmemoria.value(8)));}
    if (espacio_enmemoria > 9 & enmemoria.length()>9){boton10->setText(tarjetas.value(enmemoria.value(9)));}
}

void servMem::paginacion(){
    if(enmemoria.length()<espacio_enmemoria){
        cargar_datos_enmemoria();
    }
    else{remplazo();}
    refrescar_botones();
    mostrar_variables_enDisco();
}

void servMem::quitar(){
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
void servMem::Server() {
    server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    bind(server, (sockaddr *)&server_addr, sizeof(server_addr));
    listen(server, 0);

    //std::cout << "Escuchando para conexiones entrantes." << std::endl;
    //printf("Escuchando para conexiones entrantes.");
    size = sizeof(client_addr);
    //    server = accept(client,(struct sockaddr *)&server_addr,&size);
    //int prueba = (client = accept(server, (struct sockaddr *)&clientAddr, &clientAddrSize));
    //        if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
    //server = accept(client,(struct sockaddr *)&serverAddr,&size);

    //client = accept(server,(struct sockaddr *)&client_addr,&size);
    if(client = accept(server,( sockaddr *)&client_addr,&size)){
        std::cout << "Cliente conectado!" << std::endl;
        //  printf("Cliente conectado!");
    }
    memset(buffer, 0, sizeof(buffer));
}
void servMem::Recibir()
{
    //                recv(server, buffer, bufsize, 0);
    recv(client, buffer, sizeof(buffer), 0);
    //if(strcmp(buffer,"       Hola Care picha     ")){
    //*buffer = NULL;
    //strcat(strcpy(buffer, buffer), "Care Picha su Padre");
    //send(client, buffer, sizeof(buffer), 0);
    //}
    //cout << "El cliente dice: " << buffer << endl;
    * mensaje =NULL;
    strcat(strcpy(mensaje, mensaje), buffer);
    eti->setText(QString(mensaje));
    memset(buffer, 0, sizeof(buffer));

}
void servMem::Enviar()
{
    //cout<<"Escribe el mensaje a enviar: ";
    //cin>>this->buffer;
    //std::string cadenaStd = cb_sockets->currentText().toStdString();
    std::string cadenaStd = cb_sockets->currentText().toStdString();
    *buffer = cadenaStd[0];
    send(client, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    //cout << "Mensaje enviado!" << endl;
}
servMem::servMem(QWidget *parent): QMainWindow(parent) {

    tarjeta * espacio_0 = new tarjeta();
    tarjeta * espacio_1 = new tarjeta();
    tarjeta * espacio_2 = new tarjeta();
    tarjeta * espacio_3 = new tarjeta();
    tarjeta * espacio_4 = new tarjeta();
    tarjeta * espacio_5 = new tarjeta();
    tarjeta * espacio_6 = new tarjeta();
    tarjeta * espacio_7 = new tarjeta();
    tarjeta * espacio_8 = new tarjeta();
    tarjeta * espacio_9 = new tarjeta();


    ventana.resize(720, 720);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Gestion de Memoria");

    espacio_enmemoria = tarjetas.length()/3;
    label_espacio->setText(QString(QString::number(espacio_enmemoria)));
    label_espacio->setFixedSize(95,30);
    label_espacio->move(20,435);
    label_espacio->setStyleSheet("QWidget {background-color:red}");

    this->mostrar_variables_enDisco();
    label_enDisco->setFixedSize(35,550);
    label_enDisco->move(300,90);
    label_enDisco->setStyleSheet("QWidget {background-color:blue}");

    label_imagenes->setFixedSize(35,550);
    label_imagenes->move(580,90);
    label_imagenes->setStyleSheet("QWidget {background-color: purple}");
    label_imagenes->setText(sin_cargar+"\n");

    this->barajar();
    this->mostrar_posiciones_asignadas();
    label_posiciones->setFixedSize(55,550);
    label_posiciones->move(620,90);
    label_posiciones->setStyleSheet("QWidget {background-color:white}");


    cb->setFixedSize(55,30);
    cb->move(135, 205);
    cb->setStyleSheet("QWidget {border: 1px solid white }");
    cb->setStyleSheet("QWidget {background-color:purple}");

    QSize sizeButton(75,80);
    this->referencias_posiciones();
    cb_posiciones->setFixedSize(55,30);
    cb_posiciones->move(135, 475);
    cb_posiciones->setStyleSheet("QWidget {border: 1px solid white }");
    cb_posiciones->setStyleSheet("QWidget {background-color:blue}");
    boton_posiciones->move(20,475 );boton_posiciones->setFixedSize(95,65);boton_posiciones->setStyleSheet("QWidget {background-color:blue}");
    label_referencias->setFixedSize(55,25);
    label_referencias->move(135,510);
    label_referencias->setStyleSheet("QWidget {background-color:white}");
    this->cortar_baraja();
    boton0->move(20,205);boton0->setFixedSize(sizeButton);boton0->setStyleSheet("QWidget {background-color:purple}");
    boton11->move(20,320 );boton11->setFixedSize(sizeButton);boton11->setStyleSheet("QWidget {background-color:yellow}");
    boton1 ->move(350,90);boton1->setFixedSize(sizeButton);boton1->setStyleSheet("QWidget {background-color:green}");
    boton2 ->move(350,205);boton2->setFixedSize(sizeButton);boton2->setStyleSheet("QWidget {background-color:green}");
    boton3 ->move(350,320);boton3->setFixedSize(sizeButton);boton3->setStyleSheet("QWidget {background-color:green}");
    boton4 ->move(350,435);boton4->setFixedSize(sizeButton);boton4->setStyleSheet("QWidget {background-color:green}");
    boton5 ->move(350,550);boton5->setFixedSize(sizeButton);boton5->setStyleSheet("QWidget {background-color:green}");
    boton6 ->move(470,90);boton6->setFixedSize(sizeButton);boton6->setStyleSheet("QWidget {background-color:green}");
    boton7 ->move(470,205);boton7->setFixedSize(sizeButton);boton7->setStyleSheet("QWidget {background-color:green}");
    boton8 ->move(470,320);boton8->setFixedSize(sizeButton);boton8->setStyleSheet("QWidget {background-color:green}");
    boton9 ->move(470,435);boton9->setFixedSize(sizeButton);boton9->setStyleSheet("QWidget {background-color:green}");
    boton10->move(470,550);boton10->setFixedSize(sizeButton);boton10->setStyleSheet("QWidget {background-color:green}");
/**
 * Estos son los objetos de la interfaz encargada de manejar la comunicación entre sockets
 */
    QSize sizeButton2(85,25);
    b_enviar->move(20, 610);b_enviar->setFixedSize(sizeButton2);
    b_enviar->setStyleSheet("QWidget {background-color:green}");

    b_recibir->move(20, 640);b_recibir->setFixedSize(sizeButton2);
    b_recibir->setStyleSheet("QWidget {background-color:gold}");

    b_conectar->move(20, 670);b_conectar->setFixedSize(sizeButton2);
    b_conectar->setStyleSheet("QWidget {background-color:navy}");

    eti->move(120, 640);
    const char *str1 = "QWidget {background-color:gold}";
    eti->setStyleSheet(str1);
    eti->setFixedSize(45, 20);

    b_buscar->move(20,105);b_buscar->setFixedSize(sizeButton);b_buscar->setStyleSheet("QWidget {background-color:maroon}");
    cb_buscar->setFixedSize(45, 20);
    cb_buscar->move(125, 105);
    cb_buscar->setStyleSheet("QWidget {border: 1px solid white}");
    cb_buscar->setStyleSheet("QWidget {background-color:maroon}");
    label_busqueda->setFixedSize(55,25);
    label_busqueda->move(125,140);
    label_busqueda->setStyleSheet("QWidget {background-color:white}");
    this->referencias_busqueda();
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
    connect(boton0, SIGNAL (clicked()), this, SLOT(paginacion()));
    connect(boton11, SIGNAL (clicked()), this, SLOT(quitar()));
    connect(boton_posiciones, SIGNAL (clicked()), this, SLOT(mostrar_posiciones()));
    connect(b_enviar, SIGNAL (clicked()), this, SLOT(Enviar()));
    connect(b_recibir, SIGNAL (clicked()), this, SLOT(Recibir()));
    connect(b_conectar, SIGNAL (clicked()), this, SLOT(Server()));
    connect(b_buscar, SIGNAL (clicked()), this, SLOT(buscar_imagen()));
    ventana.show();
}
/**
 */
servMem::~servMem(){}