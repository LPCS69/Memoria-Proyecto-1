//
// Created by pablo on 8/4/22.
//

#include "servidorMememoria.h"


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
/**
 * Este metodo se encarga de asignar a una variabnle los datos que no se han cargado en memoria y mostrarlos
 * en una etiqueta.
 */
void servidorMememoria::mostrar_variables_enDisco() {
    int cont = 0;
    sin_cargar = "";
    if(enmemoria.empty()){
    while (cont < tarjetas.length()){
            sin_cargar = sin_cargar + "|" + tarjetas.value(cont) + "\n";
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
 * Este metodo se encarga de mostrar las imagenes que siguen en juego a traves de un label, se muestran en orden vertical
 *
 */
void servidorMememoria::mostrar_imagenes_enjuego() {
    int cont = 0;
    imagenes_enjuego = "";
        while (cont < tarjetas.length()){
            imagenes_enjuego = imagenes_enjuego + "|" + tarjetas.value(cont) + "\n";
            cont++;
        }
    label_imagenes->setText(imagenes_enjuego+"\n");

}
/**
 * Este metodo se encarga de mostrar las posiciones de la martiz del juego que se le han asignado a cada imagen, de forma vertical
 * para que esten en linea a su imaagen correspondiente
 *
 */
void servidorMememoria::mostrar_posiciones_asignadas()  {
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
 * Esta funcion carga de forma aleatoria los valores de las posiciones que siguen en juego, en un vector ajustado al tamaño
 * de la cantidad disponbibles
 */
void servidorMememoria::barajar() {
    int num;
    srand(time(NULL));

    while(posiciones_barajadas.length()<posiciones.length()) {
        num = rand() % posiciones.length();
        if (posiciones_barajadas.contains(posiciones.value(num))==false){
            posiciones_barajadas.push_front(posiciones.value(num));}
    }
    this->cortar_baraja();
}
/**
 * Este metodo crea un vector de vectores de dos valores llenando uno a uno con valores extraidos del vector creado aleatoriamente
 * para que este vector de vectores coincida en tamaño con el vector dondes estan las refrencias de las imagenes, para lo cual al
 * un indice en el vector de vectores con las posiciones este mismo indice coincide con una imagen y asi van a estar vinculadas
 * las imagenes a sus posiciones.
 */
void servidorMememoria::cortar_baraja() {
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
/**
 * Los botones que estan en el ejecutable del juego, solo envian un valor que indica la posicion del boton, el cual es un string con algun
 * un numero del 0 al 59, que vendrian a ser las 60 posibles posiciones que puede tener cada tarjeta, cada una des estas
 * referencias son las que se almacenan en el vector que vendria a ser la memmoria virtual, para poder llamar cualquier imagen
 * es necesario que se almacene en este vector.
 * Este metodo carga las posicones indicadas desde el otro ejecutable siempre y cuando haya espacio.
 */
void servidorMememoria::cargar_datos_enmemoria(){
    if(!enmemoria.contains(imagen_seleccion)){
    enmemoria.push_front(imagen_seleccion);}
}
/**
 * Este metodo usa el dato recibido del usuario de la posicion del boton que simula ser la tarjet, en forma de string
 * busca dentro del vector de vectores en que posicion esta esa posicion para retornar el indice que es el mismo que se utiliza
 * para referenciar una imagen del vector de las imagenes y esta por defecto en la logica implementada es la imagen de dicha
 * posicion del boton.
 *
 */
void servidorMememoria::buscar_imagen() {
    int cont = 0;
    while (!posiciones_imagenes.value(cont).contains(seleccion_jugador)){
        cont++;
    }
    imagen_seleccion = cont;
    this->paginacion();
    boton_enviar->setEnabled(true);
}
/**
 * Para simular la memoria virtual se usa una cola, en el momento que la cantidad de datos cargados excede
 * su limite, se descarga el primero que se ingreso para abrirle campo al nuevo dato que se necesita ingresar.
 */
void servidorMememoria::remplazo(){
    if(!enmemoria.contains(imagen_seleccion)){
    enmemoria.pop_back();
    enmemoria.push_front(imagen_seleccion);
    }
}
/**
 * Al encontrar una pareja se quita el dato cargado en la memoria virtual y se respeta el orden de ingreso ya establecido, al
 * quitar un dato para que sea visible en la interfaz sin que se quede el dato mostrado en la interfaz, se limpian todos y
 * solo se vuelve a mostrar los datos que siguen cargados en la memoria virtual.
 */
void servidorMememoria::limpiar_botones(){
    boton1->setText("");
    if(espacio_enmemoria > 1  & enmemoria.length()>1){boton2->setText("");}
    if(espacio_enmemoria > 2  & enmemoria.length()>2){boton3->setText("");}
    if (espacio_enmemoria > 3 & enmemoria.length()>3){boton4->setText("");}
    if (espacio_enmemoria > 4 & enmemoria.length()>4){boton5->setText("");}
    if (espacio_enmemoria > 5 & enmemoria.length()>5){boton6->setText("");}
    if (espacio_enmemoria > 6 & enmemoria.length()>6){boton7->setText("");}
    if (espacio_enmemoria > 7 & enmemoria.length()>7){boton8->setText("");}
    if (espacio_enmemoria > 8 & enmemoria.length()>8){boton9->setText("");}
    if (espacio_enmemoria > 9 & enmemoria.length()>9){boton10->setText("");}
}
/**
 * Este metodo se encarga de mostrar cada cambio que se de en los datos cargados en memmoria, se escogio botones nuevamente
 * para mostrar las imagenes, pero al final se dejo solo el nombre de la imagen que se usa para desplegarla, para asi poder
 * ver como se comporta en el resto de la interfaz que se usa para mostrar los cambios hechos por la gestion de memoria.
 */
void servidorMememoria::refrescar_botones(){
    if(!enmemoria.empty()){
    boton1->setText(tarjetas.value(enmemoria.value(0)));}
    if (espacio_enmemoria > 1  & enmemoria.length()>1){boton2->setText(tarjetas.value(enmemoria.value(1)));}
    if (espacio_enmemoria > 2  & enmemoria.length()>2){boton3->setText(tarjetas.value(enmemoria.value(2)));}
    if (espacio_enmemoria > 3 & enmemoria.length()>3){boton4->setText(tarjetas.value(enmemoria.value(3)));}
    if (espacio_enmemoria > 4 & enmemoria.length()>4){boton5->setText(tarjetas.value(enmemoria.value(4)));}
    if (espacio_enmemoria > 5 & enmemoria.length()>5){boton6->setText(tarjetas.value(enmemoria.value(5)));}
    if (espacio_enmemoria > 6 & enmemoria.length()>6){boton7->setText(tarjetas.value(enmemoria.value(6)));}
    if (espacio_enmemoria > 7 & enmemoria.length()>7){boton8->setText(tarjetas.value(enmemoria.value(7)));}
    if (espacio_enmemoria > 8 & enmemoria.length()>8){boton9->setText(tarjetas.value(enmemoria.value(8)));}
    if (espacio_enmemoria > 9 & enmemoria.length()>9){boton10->setText(tarjetas.value(enmemoria.value(9)));}
}
/**
 * La estructura de datos que se utilizo para simular la memoria virtual, puede crecer dinamicamente, pero ya que se pide
 * que tenga un limite, se usa una variable que siempre va ser un tercio de la cantidad de paginas disponibles y se pone la
 * condicion de que en el momento que se rebase dicho limite, se llame el metodo que se encarga del remplazo.
 */
void servidorMememoria::paginacion(){
    if(enmemoria.length()<espacio_enmemoria){
        cargar_datos_enmemoria();
    }
    else{remplazo();}
    refrescar_botones();
    mostrar_variables_enDisco();
}
/**
 * Para hacer mas visible cuando se reduce ele espacio de la memoria virtual, se quitan el objeto que simula ser un
 * campo en memoria.
 */
void servidorMememoria::quitar(){
    if (0<tarjetas.length()){

        if (espacio_enmemoria < 10){boton10->close();}; if (espacio_enmemoria < 9){boton9->close();};
        if (espacio_enmemoria <  8){boton8 ->close();}; if (espacio_enmemoria < 7){boton7->close();};
        if (espacio_enmemoria <  6){boton6 ->close();}; if (espacio_enmemoria < 5){boton5->close();};
        if (espacio_enmemoria <  4){boton4 ->close();}; if (espacio_enmemoria < 3){boton3->close();};
        if (espacio_enmemoria <  2){boton2 ->close();}; if (espacio_enmemoria < 1){boton1->close();};

    }  }

/**
 * Este metodo crea la conexion con el otro ejecutble y lo hace como servidor.
 */

void servidorMememoria::Server() {
    server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    bind(server, (sockaddr *)&server_addr, sizeof(server_addr));
    listen(server, 0);


    size = sizeof(client_addr);

    if(client = accept(server,( sockaddr *)&client_addr,&size)){
        std::cout << "Cliente conectado!" << std::endl;
    }
    memset(buffer, 0, sizeof(buffer));
    boton_conectar->setEnabled(false);
}
/**
 * Este metodo recibe los datos del otro ejecutable
 */
void servidorMememoria::Recibir(){
    recv(client, buffer, sizeof(buffer), 0);

    * mensaje =NULL;
    strcat(strcpy(mensaje, mensaje), buffer);
    eti->setText(QString(mensaje));
    seleccion_jugador = mensaje;
    memset(buffer, 0, sizeof(buffer));
    boton_recibir->setEnabled(false);
    buscar_imagen();
}
/**
 * Se encarga de enviar los datos al otro ejecutable.
 */
void servidorMememoria::Enviar(){
    std::string string_temp = tarjetas.value(imagen_seleccion).toStdString();
    char const * char_temp = &string_temp[0];
    strcat(strcpy(buffer, buffer),char_temp );
    send(client, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    boton_enviar->setEnabled(false);
    boton_recibir->setEnabled(true);
    tarjetas_seleccionadas.append(seleccion_jugador);
    imagenes_destapadas.append(tarjetas.value(imagen_seleccion));

    std::string string_prueba = imagenes_destapadas.last().toStdString();
    char const * prueba = &string_prueba[0];
    std::cout << prueba << std::endl;
    encontrar_pareja();
}
/**
 * Lo que se guarda en memoria son refrencias de las posiciones de las imagenes del vector donde estan guardadas,
 * al hacer esto se genera un error al reducir el vector que contiene los strings para cargar las imagenes,
 * los indices de las puede que accedan a otras imagenes, por esto antes de reducir la cantidad de posibles imagenes a cargar,
 * se hace un respaldo de las que hay cargadas en memoria, para luegor cargar los indices respecto al nuevo vector que va
 * contener los datos para poder acceder a las imagenes.
 */
void servidorMememoria::respaldo_imagenesenmemoria(){
    int cont =0;
    while (cont < enmemoria.length()){
        imagenes_enmemoria.append(tarjetas.value(enmemoria.value(cont)));
        cont++;
    }
}
/**
 * Vuelve a cargar en memoria las posiciones de las imagenes que ya estaban en memoria, respecto al nuevo vector
 * despues de eliminar las imagenes emparejadas.
 */
void servidorMememoria::cargar_respaldo(){
    int cont = 0;
    while (cont < imagenes_enmemoria.length()){
        enmemoria.append(tarjetas.indexOf(imagenes_enmemoria.value(cont)));
        cont++;
    }
    imagenes_enmemoria.clear();
}

void servidorMememoria::encontrar_pareja() {
    if (tarjetas_seleccionadas.length() == limite_destape){
        if (imagenes_destapadas.value(0)== imagenes_destapadas.value(1)){
            this->limpiar_botones();
            std::cout << "Son Pareja" << std::endl;

            this->respaldo_imagenesenmemoria();
            enmemoria.clear();
            imagenes_enmemoria.removeAll(tarjetas.value(imagen_seleccion));
            tarjetas.removeAll(tarjetas.value(imagen_seleccion));
            this->cargar_respaldo();
            espacio_enmemoria = tarjetas.length()/3;
            label_espacio->setText(QString(QString::number(espacio_enmemoria)));
            this->quitar();
            posiciones.removeAll(tarjetas_seleccionadas.value(0));
            posiciones.removeAll(tarjetas_seleccionadas.value(1));
            posiciones_barajadas.clear();
            posiciones_imagenes.clear();
            this->mostrar_variables_enDisco();
            this->mostrar_imagenes_enjuego();
            this->barajar();
            this->mostrar_posiciones_asignadas();
            refrescar_botones();
            if(turno== 1){
                parejas_jugador1++;
                label_jugador1->setText("Jugador 1:  " + QString::number(parejas_jugador1));
            }
            else {
                parejas_jugador2++;
                label_jugador2->setText("Jugador 2:  " + QString::number(parejas_jugador2));
            }

        }
        if (turno == 1){
            turno =2;
            label_turno_enjuego->setText("Turno: Jugador 2");

        }
        else{
            turno =1;
            label_turno_enjuego->setText("Turno: Jugador 1");

        }
        tarjetas_seleccionadas.clear();
        imagenes_destapadas.clear();
    }
}

servidorMememoria::servidorMememoria(QWidget *parent): QMainWindow(parent) {

    ventana.resize(650, 720);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Gestion de Memoria");

    espacio_enmemoria = tarjetas.length()/3;
    label_espacio->setText(QString(QString::number(espacio_enmemoria)));
    label_espacio->setFixedSize(35,30);
    label_espacio->move(250,60);
    label_espacio->setStyleSheet("QWidget {background-color:red}");

    this->mostrar_variables_enDisco();
    label_enDisco->setFixedSize(35,550);
    label_enDisco->move(250,90);
    label_enDisco->setStyleSheet("QWidget {background-color:blue}");

    label_imagenes->setFixedSize(35,550);
    label_imagenes->move(530,90);
    label_imagenes->setStyleSheet("QWidget {background-color: purple}");
    this->mostrar_imagenes_enjuego();


    this->barajar();
    this->mostrar_posiciones_asignadas();
    label_posiciones->setFixedSize(55,550);
    label_posiciones->move(570,90);
    label_posiciones->setStyleSheet("QWidget {background-color:white}");

    label_turno_enjuego->setFixedSize(155,55);
    label_turno_enjuego->move(20,60);
    label_turno_enjuego->setText("Turno: Jugador 1");
    label_turno_enjuego->setStyleSheet("QWidget {color:gold}");

    label_jugador1->setFixedSize(155,55);
    label_jugador1->move(20,120);
    label_jugador1->setText("Jugador 1:  " + QString::number(parejas_jugador1));
    label_jugador1->setStyleSheet("QWidget {color:red}");

    label_jugador2->setFixedSize(155,55);
    label_jugador2->move(20,180);
    label_jugador2->setText("Jugador 2:  "+ QString::number(parejas_jugador1));
    label_jugador2->setStyleSheet("QWidget {color:blue}");

    QSize sizeButton(75,80);
 //   this->referencias_posiciones();

    boton1 ->move(300,90);boton1->setFixedSize(sizeButton);boton1->setStyleSheet("QWidget {background-color:green}");
    boton2 ->move(300,205);boton2->setFixedSize(sizeButton);boton2->setStyleSheet("QWidget {background-color:green}");
    boton3 ->move(300,320);boton3->setFixedSize(sizeButton);boton3->setStyleSheet("QWidget {background-color:green}");
    boton4 ->move(300,435);boton4->setFixedSize(sizeButton);boton4->setStyleSheet("QWidget {background-color:green}");
    boton5 ->move(300,550);boton5->setFixedSize(sizeButton);boton5->setStyleSheet("QWidget {background-color:green}");
    boton6 ->move(420,90);boton6->setFixedSize(sizeButton);boton6->setStyleSheet("QWidget {background-color:green}");
    boton7 ->move(420,205);boton7->setFixedSize(sizeButton);boton7->setStyleSheet("QWidget {background-color:green}");
    boton8 ->move(420,320);boton8->setFixedSize(sizeButton);boton8->setStyleSheet("QWidget {background-color:green}");
    boton9 ->move(420,435);boton9->setFixedSize(sizeButton);boton9->setStyleSheet("QWidget {background-color:green}");
    boton10->move(420,550);boton10->setFixedSize(sizeButton);boton10->setStyleSheet("QWidget {background-color:green}");
/**
 * Estos son los objetos de la interfaz encargada de manejar la comunicación entre sockets
 */
    QSize sizeButton2(85,25);

    boton_recibir->move(20, 550);boton_recibir->setFixedSize(sizeButton2);
    boton_recibir->setStyleSheet("QWidget {background-color:gold}");

    eti->move(120, 550);
    eti->setStyleSheet("QWidget {background-color:gold}");
    eti->setFixedSize(45, 20);

    boton_enviar->move(20, 580);boton_enviar->setFixedSize(sizeButton2);
    boton_enviar->setStyleSheet("QWidget {background-color:green}");
    boton_enviar->setEnabled(false);

    boton_conectar->move(20, 610);boton_conectar->setFixedSize(sizeButton2);
    boton_conectar->setStyleSheet("QWidget {background-color:navy}");

    connect(boton_enviar, SIGNAL (clicked()), this, SLOT(Enviar()));
    connect(boton_recibir, SIGNAL (clicked()), this, SLOT(Recibir()));
    connect(boton_conectar, SIGNAL (clicked()), this, SLOT(Server()));
    ventana.show();
}
servidorMememoria::~servidorMememoria(){}