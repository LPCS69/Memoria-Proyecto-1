//
// Created by pablo on 10/4/22.
//

#include "clienteMemoria.h"
void clienteMemoria::Cliente(){
    server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    ::connect(server,(struct sockaddr *)&addr, sizeof(addr));
    memset(buffer, 0, sizeof(buffer));
    conectado = true;
    boton_conectar->setEnabled(false);
}
void clienteMemoria::Enviar()
{

    std::string tmp = std::to_string(escogencia);
    char const *num_char = tmp.c_str();

    strcat(strcpy(buffer, buffer),num_char );
    send(server, buffer, sizeof(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    enviando = true;
    boton_recibir->setEnabled(true);
    boton_enviar->setEnabled(false);
    tarjetas_destapadas.append(escogencia);

}
void clienteMemoria::Recibir()
{
    recv(server, buffer, sizeof(buffer), 0);

    * mensaje =NULL;
    strcat(strcpy(mensaje, mensaje), buffer);
    label_recibir->setText(QString(mensaje));
    imagen = mensaje;
    this->girar_tarjeta(escogencia, imagen);
    imagenes_destapadas.append(imagen);
    memset(buffer, 0, sizeof(buffer));
    enviando = false;
    label_escogencia->setText("");
    boton_recibir->setEnabled(false);
}
void clienteMemoria::CerrarSocket()
{
    ::close(server);

}
/**
 * A cada boton se le asigno una funcion que llama a este metodo, lo que vaira es el parametro de cada boton, ya que va ser la referencia de sus posicion
 * en el tablero, estos son los botones que simulan ser las tarjetas
 * @param num
 */
void clienteMemoria::posicion_aux(int num) {
    if (conectado) {
        if (!enviando) {
                if (limite_destape == tarjetas_destapadas.length()) {
                    encontrar_pareja();

                }

                else if ((!tarjetas_destapadas.contains(num)) & destapar) {
                    escogencia = num;
                    label_escogencia->setText(QString::number(num));
                    boton_enviar->setEnabled(true);
                    label_recibir->setText("");
                }

        }
    }
}
/**
 * En el turno de cada jugador se almacenan momentaneamente los strings para acceder a las imagenes, cuando
 * se destapo la cantidad de tarjetas permitidas se evaluan si estan son iguales, si lo son se quitan los botones del juego sino se
 * restauran y alk final siempre se limpian los vectores que almacenan las posiciones usadas y las imagenes cargadas, para que esten disponibles para el
 * siguiente turno.
 */
void clienteMemoria::encontrar_pareja() {
        if (imagenes_destapadas.value(0) == imagenes_destapadas.value(1)){
            this->quitar_pareja(tarjetas_destapadas.value(0));
            this->quitar_pareja(tarjetas_destapadas.value(1));



        }

    else{
            this->girar_tarjeta(tarjetas_destapadas.value(0),"Back-Card");
            this->girar_tarjeta(tarjetas_destapadas.value(1),"Back-Card");

    }
    tarjetas_destapadas.clear();
    imagenes_destapadas.clear();
}
/**
 * Este metodo se encarga de cerrar los botones que salen del juego porque se lograron emparejar, recibe como parametro un numero el cual es la referencia de cual
 * boton hay que cerrar.
 * @param num
 */
void clienteMemoria::quitar_pareja(int num) {
    if (num == 0){boton0->close();}if (num == 1){boton1->close();}
    if (num == 2){boton2->close();}if (num == 3){boton3->close();}
    if (num == 4){boton4->close();}if (num == 5){boton5->close();}
    if (num == 6){boton6->close();}if (num == 7){boton7->close();}
    if (num == 8){boton8->close();}if (num == 9){boton9->close();}

    if (num == 10){boton10->close();}if (num == 11){boton11->close();}
    if (num == 12){boton12->close();}if (num == 13){boton13->close();}
    if (num == 14){boton14->close();}if (num == 15){boton15->close();}
    if (num == 16){boton16->close();}if (num == 17){boton17->close();}
    if (num == 18){boton18->close();}if (num == 19){boton19->close();}

    if (num == 20){boton20->close();}if (num == 21){boton21->close();}
    if (num == 22){boton22->close();}if (num == 23){boton23->close();}
    if (num == 24){boton24->close();}if (num == 25){boton25->close();}
    if (num == 26){boton26->close();}if (num == 27){boton27->close();}
    if (num == 28){boton28->close();}if (num == 29){boton29->close();}

    if (num == 30){boton30->close();}if (num == 31){boton31->close();}
    if (num == 32){boton32->close();}if (num == 33){boton33->close();}
    if (num == 34){boton34->close();}if (num == 35){boton35->close();}
    if (num == 36){boton36->close();}if (num == 37){boton37->close();}
    if (num == 38){boton38->close();}if (num == 39){boton39->close();}

    if (num == 40){boton40->close();}if (num == 41){boton41->close();}
    if (num == 42){boton42->close();}if (num == 43){boton43->close();}
    if (num == 44){boton44->close();}if (num == 45){boton45->close();}
    if (num == 46){boton46->close();}if (num == 47){boton47->close();}
    if (num == 48){boton48->close();}if (num == 49){boton49->close();}

    if (num == 50){boton50->close();}if (num == 51){boton51->close();}
    if (num == 52){boton52->close();}if (num == 53){boton53->close();}
    if (num == 54){boton54->close();}if (num == 55){boton55->close();}
    if (num == 56){boton56->close();}if (num == 57){boton57->close();}
    if (num == 58){boton58->close();}if (num == 59){boton59->close();}
}
/**
 * Este metodo recibe como parametro la referencia del boton o tarjeta y la imaghen que se le va cargar, se usa tanto como para cargar la imagen frontal
 * cuando se destapa, como parc aargar la imagen trasera para restaurar un boton en caso de que nosea pareja de la otra tarjeta destapada.
 * @param numero_carta
 * @param imagen_carta
 */
void clienteMemoria::girar_tarjeta(int numero_carta, QString imagen_carta) {
    if (numero_carta == 0){boton0->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 1){boton1->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 2){boton2->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 3){boton3->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 4){boton4->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 5){boton5->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 6){boton6->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 7){boton7->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 8){boton8->setIcon(QIcon(QPixmap(imagen_carta)));;}if (numero_carta == 9){boton9->setIcon(QIcon(QPixmap(imagen_carta)));}

    if (numero_carta == 10){boton10->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 11){boton11->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 12){boton12->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 13){boton13->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 14){boton14->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 15){boton15->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 16){boton16->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 17){boton17->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 18){boton18->setIcon(QIcon(QPixmap(imagen_carta)));;}if (numero_carta == 19){boton19->setIcon(QIcon(QPixmap(imagen_carta)));}

    if (numero_carta == 20){boton20->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 21){boton21->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 22){boton22->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 23){boton23->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 24){boton24->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 25){boton25->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 26){boton26->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 27){boton27->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 28){boton28->setIcon(QIcon(QPixmap(imagen_carta)));;}if (numero_carta == 29){boton29->setIcon(QIcon(QPixmap(imagen_carta)));}

    if (numero_carta == 30){boton30->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 31){boton31->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 32){boton32->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 33){boton33->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 34){boton34->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 35){boton35->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 36){boton36->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 37){boton37->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 38){boton38->setIcon(QIcon(QPixmap(imagen_carta)));;}if (numero_carta == 39){boton39->setIcon(QIcon(QPixmap(imagen_carta)));}

    if (numero_carta == 40){boton40->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 41){boton41->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 42){boton42->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 43){boton43->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 44){boton44->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 45){boton45->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 46){boton46->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 47){boton47->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 48){boton48->setIcon(QIcon(QPixmap(imagen_carta)));;}if (numero_carta == 49){boton49->setIcon(QIcon(QPixmap(imagen_carta)));}

    if (numero_carta == 50){boton50->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 51){boton51->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 52){boton52->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 53){boton53->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 54){boton54->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 55){boton55->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 56){boton56->setIcon(QIcon(QPixmap(imagen_carta)));}if (numero_carta == 57){boton57->setIcon(QIcon(QPixmap(imagen_carta)));}
    if (numero_carta == 58){boton58->setIcon(QIcon(QPixmap(imagen_carta)));;}if (numero_carta == 59){boton59->setIcon(QIcon(QPixmap(imagen_carta)));}

}
/**
 * Estas lineas definen la funcion para cada boton, todas llaman la misma funcion pero usando un parametro unico para identificar cual boton es el que fue presionado,
 * lo que vendria a representar cual tarjeta fue girada o selleccionada.
 */

void clienteMemoria::posicion0() {this->posicion_aux(0);}void clienteMemoria::posicion1() {this->posicion_aux(1);}
void clienteMemoria::posicion2() {this->posicion_aux(2);}void clienteMemoria::posicion3() {this->posicion_aux(3);}
void clienteMemoria::posicion4() {this->posicion_aux(4);}void clienteMemoria::posicion5() {this->posicion_aux(5);}
void clienteMemoria::posicion6() {this->posicion_aux(6);}void clienteMemoria::posicion7() {this->posicion_aux(7);}
void clienteMemoria::posicion8() {this->posicion_aux(8);}void clienteMemoria::posicion9() {this->posicion_aux(9);}

void clienteMemoria::posicion10() {this->posicion_aux(10);}void clienteMemoria::posicion11() {this->posicion_aux(11);}
void clienteMemoria::posicion12() {this->posicion_aux(12);}void clienteMemoria::posicion13() {this->posicion_aux(13);}
void clienteMemoria::posicion14() {this->posicion_aux(14);}void clienteMemoria::posicion15() {this->posicion_aux(15);}
void clienteMemoria::posicion16() {this->posicion_aux(16);}void clienteMemoria::posicion17() {this->posicion_aux(17);}
void clienteMemoria::posicion18() {this->posicion_aux(18);}void clienteMemoria::posicion19() {this->posicion_aux(19);}

void clienteMemoria::posicion20() {this->posicion_aux(20);}void clienteMemoria::posicion21() {this->posicion_aux(21);}
void clienteMemoria::posicion22() {this->posicion_aux(22);}void clienteMemoria::posicion23() {this->posicion_aux(23);}
void clienteMemoria::posicion24() {this->posicion_aux(24);}void clienteMemoria::posicion25() {this->posicion_aux(25);}
void clienteMemoria::posicion26() {this->posicion_aux(26);}void clienteMemoria::posicion27() {this->posicion_aux(27);}
void clienteMemoria::posicion28() {this->posicion_aux(28);}void clienteMemoria::posicion29() {this->posicion_aux(29);}

void clienteMemoria::posicion30() {this->posicion_aux(30);}void clienteMemoria::posicion31() {this->posicion_aux(31);}
void clienteMemoria::posicion32() {this->posicion_aux(32);}void clienteMemoria::posicion33() {this->posicion_aux(33);}
void clienteMemoria::posicion34() {this->posicion_aux(34);}void clienteMemoria::posicion35() {this->posicion_aux(35);}
void clienteMemoria::posicion36() {this->posicion_aux(36);}void clienteMemoria::posicion37() {this->posicion_aux(37);}
void clienteMemoria::posicion38() {this->posicion_aux(38);}void clienteMemoria::posicion39() {this->posicion_aux(39);}

void clienteMemoria::posicion40() {this->posicion_aux(40);}void clienteMemoria::posicion41() {this->posicion_aux(41);}
void clienteMemoria::posicion42() {this->posicion_aux(42);}void clienteMemoria::posicion43() {this->posicion_aux(43);}
void clienteMemoria::posicion44() {this->posicion_aux(44);}void clienteMemoria::posicion45() {this->posicion_aux(45);}
void clienteMemoria::posicion46() {this->posicion_aux(46);}void clienteMemoria::posicion47() {this->posicion_aux(47);}
void clienteMemoria::posicion48() {this->posicion_aux(48);}void clienteMemoria::posicion49() {this->posicion_aux(49);}

void clienteMemoria::posicion50() {this->posicion_aux(50);}void clienteMemoria::posicion51() {this->posicion_aux(51);}
void clienteMemoria::posicion52() {this->posicion_aux(52);}void clienteMemoria::posicion53() {this->posicion_aux(53);}
void clienteMemoria::posicion54() {this->posicion_aux(54);}void clienteMemoria::posicion55() {this->posicion_aux(55);}
void clienteMemoria::posicion56() {this->posicion_aux(56);}void clienteMemoria::posicion57() {this->posicion_aux(57);}
void clienteMemoria::posicion58() {this->posicion_aux(58);}void clienteMemoria::posicion59() {this->posicion_aux(59);}
clienteMemoria::clienteMemoria(QWidget *parent): QMainWindow(parent) {
    ventana.resize(1024, 720);
    ventana.setStyleSheet("QWidget {background-color:black}");
    ventana.setWindowTitle("Memoria");


/**
 * Estos son los objetos de la interfaz encargada de manejar la comunicación entre sockets
 */
    QSize sizeButton2(85,25);
    boton_enviar->move(20, 630);
    boton_enviar->setFixedSize(sizeButton2);
    boton_enviar->setStyleSheet("QWidget {background-color:green}");
    boton_enviar->setEnabled(false);

    boton_recibir->move(20, 660);
    boton_recibir->setFixedSize(sizeButton2);
    boton_recibir->setStyleSheet("QWidget {background-color:gold}");
    boton_recibir->setEnabled(false);

    boton_conectar->move(20, 690);
    boton_conectar->setFixedSize(sizeButton2);
    boton_conectar->setStyleSheet("QWidget {background-color:navy}");

    label_recibir->move(120, 660);
    label_recibir->setStyleSheet("QWidget {background-color:gold}");
    label_recibir->setFixedSize(45, 20);

    label_escogencia->move(120, 630);
    label_escogencia->setStyleSheet("QWidget {background-color:white}");
    label_escogencia->setFixedSize(45, 20);


    QString color_l = "QWidget {color:red}";
    QSize sizeLabel(20, 13);

    label_numeracion0->move(50, 105);label_numeracion0->setFixedSize(sizeLabel);
    label_numeracion0->setText("0");label_numeracion0->setStyleSheet(color_l);
    label_numeracion1->move(150, 105);label_numeracion1->setFixedSize(sizeLabel);
    label_numeracion1->setText("1");label_numeracion1->setStyleSheet(color_l);
    label_numeracion2->move(250, 105);label_numeracion2->setFixedSize(sizeLabel);
    label_numeracion2->setText("2");label_numeracion2->setStyleSheet(color_l);
    label_numeracion3->move(350, 105);label_numeracion3->setFixedSize(sizeLabel);
    label_numeracion3->setText("3");label_numeracion3->setStyleSheet(color_l);
    label_numeracion4->move(450, 105);label_numeracion4->setFixedSize(sizeLabel);
    label_numeracion4->setText("4");label_numeracion4->setStyleSheet(color_l);
    label_numeracion5->move(550, 105);label_numeracion5->setFixedSize(sizeLabel);
    label_numeracion5->setText("5");label_numeracion5->setStyleSheet(color_l);
    label_numeracion6->move(650, 105);label_numeracion6->setFixedSize(sizeLabel);
    label_numeracion6->setText("6");label_numeracion6->setStyleSheet(color_l);
    label_numeracion7->move(750, 105);label_numeracion7->setFixedSize(sizeLabel);
    label_numeracion7->setText("7");label_numeracion7->setStyleSheet(color_l);
    label_numeracion8->move(850, 105);label_numeracion8->setFixedSize(sizeLabel);
    label_numeracion8->setText("8");label_numeracion8->setStyleSheet(color_l);
    label_numeracion9->move(950, 105);label_numeracion9->setFixedSize(sizeLabel);
    label_numeracion9->setText("9");label_numeracion9->setStyleSheet(color_l);

    label_numeracion10->move(50, 205);label_numeracion10->setFixedSize(sizeLabel);
    label_numeracion10->setText("10");label_numeracion10->setStyleSheet(color_l);
    label_numeracion11->move(150, 205);label_numeracion11->setFixedSize(sizeLabel);
    label_numeracion11->setText("11");label_numeracion11->setStyleSheet(color_l);
    label_numeracion12->move(250, 205);label_numeracion12->setFixedSize(sizeLabel);
    label_numeracion12->setText("12");label_numeracion12->setStyleSheet(color_l);
    label_numeracion13->move(350, 205);label_numeracion13->setFixedSize(sizeLabel);
    label_numeracion13->setText("13");label_numeracion13->setStyleSheet(color_l);
    label_numeracion14->move(450, 205);label_numeracion14->setFixedSize(sizeLabel);
    label_numeracion14->setText("14");label_numeracion14->setStyleSheet(color_l);
    label_numeracion15->move(550, 205);label_numeracion15->setFixedSize(sizeLabel);
    label_numeracion15->setText("15");label_numeracion15->setStyleSheet(color_l);
    label_numeracion16->move(650, 205);label_numeracion16->setFixedSize(sizeLabel);
    label_numeracion16->setText("16");label_numeracion16->setStyleSheet(color_l);
    label_numeracion17->move(750, 205);label_numeracion17->setFixedSize(sizeLabel);
    label_numeracion17->setText("17");label_numeracion17->setStyleSheet(color_l);
    label_numeracion18->move(850, 205);label_numeracion18->setFixedSize(sizeLabel);
    label_numeracion18->setText("18");label_numeracion18->setStyleSheet(color_l);
    label_numeracion19->move(950, 205);label_numeracion19->setFixedSize(sizeLabel);
    label_numeracion19->setText("19");label_numeracion19->setStyleSheet(color_l);

    label_numeracion20->move(50, 305);label_numeracion20->setFixedSize(sizeLabel);
    label_numeracion20->setText("20");label_numeracion20->setStyleSheet(color_l);
    label_numeracion21->move(150, 305);label_numeracion21->setFixedSize(sizeLabel);
    label_numeracion21->setText("21");label_numeracion21->setStyleSheet(color_l);
    label_numeracion22->move(250, 305);label_numeracion22->setFixedSize(sizeLabel);
    label_numeracion22->setText("22");label_numeracion22->setStyleSheet(color_l);
    label_numeracion23->move(350, 305);label_numeracion23->setFixedSize(sizeLabel);
    label_numeracion23->setText("23");label_numeracion23->setStyleSheet(color_l);
    label_numeracion24->move(450, 305);label_numeracion24->setFixedSize(sizeLabel);
    label_numeracion24->setText("24");label_numeracion24->setStyleSheet(color_l);
    label_numeracion25->move(550, 305);label_numeracion25->setFixedSize(sizeLabel);
    label_numeracion25->setText("25");label_numeracion25->setStyleSheet(color_l);
    label_numeracion26->move(650, 305);label_numeracion26->setFixedSize(sizeLabel);
    label_numeracion26->setText("26");label_numeracion26->setStyleSheet(color_l);
    label_numeracion27->move(750, 305);label_numeracion27->setFixedSize(sizeLabel);
    label_numeracion27->setText("27");label_numeracion27->setStyleSheet(color_l);
    label_numeracion28->move(850, 305);label_numeracion28->setFixedSize(sizeLabel);
    label_numeracion28->setText("28");label_numeracion28->setStyleSheet(color_l);
    label_numeracion29->move(950, 305);label_numeracion29->setFixedSize(sizeLabel);
    label_numeracion29->setText("29");label_numeracion29->setStyleSheet(color_l);

    label_numeracion30->move(50, 405);label_numeracion30->setFixedSize(sizeLabel);
    label_numeracion30->setText("30");label_numeracion30->setStyleSheet(color_l);
    label_numeracion31->move(150, 405);label_numeracion31->setFixedSize(sizeLabel);
    label_numeracion31->setText("31");label_numeracion31->setStyleSheet(color_l);
    label_numeracion32->move(250, 405);label_numeracion32->setFixedSize(sizeLabel);
    label_numeracion32->setText("32");label_numeracion32->setStyleSheet(color_l);
    label_numeracion33->move(350, 405);label_numeracion33->setFixedSize(sizeLabel);
    label_numeracion33->setText("33");label_numeracion33->setStyleSheet(color_l);
    label_numeracion34->move(450, 405);label_numeracion34->setFixedSize(sizeLabel);
    label_numeracion34->setText("34");label_numeracion34->setStyleSheet(color_l);
    label_numeracion35->move(550, 405);label_numeracion35->setFixedSize(sizeLabel);
    label_numeracion35->setText("35");label_numeracion35->setStyleSheet(color_l);
    label_numeracion36->move(650, 405);label_numeracion36->setFixedSize(sizeLabel);
    label_numeracion36->setText("36");label_numeracion36->setStyleSheet(color_l);
    label_numeracion37->move(750, 405);label_numeracion37->setFixedSize(sizeLabel);
    label_numeracion37->setText("37");label_numeracion37->setStyleSheet(color_l);
    label_numeracion38->move(850, 405);label_numeracion38->setFixedSize(sizeLabel);
    label_numeracion38->setText("38");label_numeracion38->setStyleSheet(color_l);
    label_numeracion39->move(950, 405);label_numeracion39->setFixedSize(sizeLabel);
    label_numeracion39->setText("39");label_numeracion39->setStyleSheet(color_l);

    label_numeracion40->move(50, 505);label_numeracion40->setFixedSize(sizeLabel);
    label_numeracion40->setText("40");label_numeracion40->setStyleSheet(color_l);
    label_numeracion41->move(150, 505);label_numeracion41->setFixedSize(sizeLabel);
    label_numeracion41->setText("41");label_numeracion41->setStyleSheet(color_l);
    label_numeracion42->move(250, 505);label_numeracion42->setFixedSize(sizeLabel);
    label_numeracion42->setText("42");label_numeracion42->setStyleSheet(color_l);
    label_numeracion43->move(350, 505);label_numeracion43->setFixedSize(sizeLabel);
    label_numeracion43->setText("43");label_numeracion43->setStyleSheet(color_l);
    label_numeracion44->move(450, 505);label_numeracion44->setFixedSize(sizeLabel);
    label_numeracion44->setText("44");label_numeracion44->setStyleSheet(color_l);
    label_numeracion45->move(550, 505);label_numeracion45->setFixedSize(sizeLabel);
    label_numeracion45->setText("45");label_numeracion45->setStyleSheet(color_l);
    label_numeracion46->move(650, 505);label_numeracion46->setFixedSize(sizeLabel);
    label_numeracion46->setText("46");label_numeracion46->setStyleSheet(color_l);
    label_numeracion47->move(750, 505);label_numeracion47->setFixedSize(sizeLabel);
    label_numeracion47->setText("47");label_numeracion47->setStyleSheet(color_l);
    label_numeracion48->move(850, 505);label_numeracion48->setFixedSize(sizeLabel);
    label_numeracion48->setText("48");label_numeracion48->setStyleSheet(color_l);
    label_numeracion49->move(950, 505);label_numeracion49->setFixedSize(sizeLabel);
    label_numeracion49->setText("49");label_numeracion49->setStyleSheet(color_l);

    label_numeracion50->move(50, 605);label_numeracion50->setFixedSize(sizeLabel);
    label_numeracion50->setText("50");label_numeracion50->setStyleSheet(color_l);
    label_numeracion51->move(150, 605);label_numeracion51->setFixedSize(sizeLabel);
    label_numeracion51->setText("51");label_numeracion51->setStyleSheet(color_l);
    label_numeracion52->move(250, 605);label_numeracion52->setFixedSize(sizeLabel);
    label_numeracion52->setText("52");label_numeracion52->setStyleSheet(color_l);
    label_numeracion53->move(350, 605);label_numeracion53->setFixedSize(sizeLabel);
    label_numeracion53->setText("53");label_numeracion53->setStyleSheet(color_l);
    label_numeracion54->move(450, 605);label_numeracion54->setFixedSize(sizeLabel);
    label_numeracion54->setText("54");label_numeracion54->setStyleSheet(color_l);
    label_numeracion55->move(550, 605);label_numeracion55->setFixedSize(sizeLabel);
    label_numeracion55->setText("55");label_numeracion55->setStyleSheet(color_l);
    label_numeracion56->move(650, 605);label_numeracion56->setFixedSize(sizeLabel);
    label_numeracion56->setText("56");label_numeracion56->setStyleSheet(color_l);
    label_numeracion57->move(750, 605);label_numeracion57->setFixedSize(sizeLabel);
    label_numeracion57->setText("57");label_numeracion57->setStyleSheet(color_l);
    label_numeracion58->move(850, 605);label_numeracion58->setFixedSize(sizeLabel);
    label_numeracion58->setText("58");label_numeracion58->setStyleSheet(color_l);
    label_numeracion59->move(950, 605);label_numeracion59->setFixedSize(sizeLabel);
    label_numeracion59->setText("59");label_numeracion59->setStyleSheet(color_l);
/**

    */
    connect( boton_enviar, SIGNAL (clicked()), this, SLOT(Enviar()));
    connect(boton_recibir, SIGNAL (clicked()), this, SLOT(Recibir()));
    connect(boton_conectar, SIGNAL (clicked()), this, SLOT(Cliente()));
/**
 * FILA1   FILA1   FILA1   FILA1   FILA1   FILA1   FILA1   FILA1   FILA1
 */
    QPixmap backCardIMage("Back-Card.jpg");
    QIcon buttonIcon(backCardIMage);
    QSize sizeButton(75,80);
    boton0->move(20,20);boton0->setFixedSize(sizeButton);
    boton0->setIcon(buttonIcon);boton0->setIconSize(backCardIMage.rect().size());

    boton1->move(120,20);boton1->setFixedSize(sizeButton);
    boton1->setIcon(buttonIcon);boton1->setIconSize(backCardIMage.rect().size());

    boton2->move(220,20);boton2->setFixedSize(sizeButton);
    boton2->setIcon(buttonIcon);boton2->setIconSize(backCardIMage.rect().size());

    boton3->move(320,20);boton3->setFixedSize(sizeButton);
    boton3->setIcon(buttonIcon);boton3->setIconSize(backCardIMage.rect().size());

    boton4->move(420,20);boton4->setFixedSize(sizeButton);
    boton4->setIcon(buttonIcon);boton4->setIconSize(backCardIMage.rect().size());

    boton5->move(520,20);boton5->setFixedSize(sizeButton);
    boton5->setIcon(buttonIcon);boton5->setIconSize(backCardIMage.rect().size());

    boton6->move(620,20);boton6->setFixedSize(sizeButton);
    boton6->setIcon(buttonIcon);boton6->setIconSize(backCardIMage.rect().size());

    boton7->move(720,20);boton7->setFixedSize(sizeButton);
    boton7->setIcon(buttonIcon);boton7->setIconSize(backCardIMage.rect().size());

    boton8->move(820,20);boton8->setFixedSize(sizeButton);
    boton8->setIcon(buttonIcon);boton8->setIconSize(backCardIMage.rect().size());

    boton9->move(920,20);boton9->setFixedSize(sizeButton);
    boton9->setIcon(buttonIcon);boton9->setIconSize(backCardIMage.rect().size());
/**
 * FILA2   FILA2   FILA2   FILA2   FILA2   FILA2   FILA2   FILA2   FILA2
 */


    boton10->move(20,120);boton10->setFixedSize(sizeButton);
    boton10->setIcon(buttonIcon);boton10->setIconSize(backCardIMage.rect().size());

    boton11->move(120,120);boton11->setFixedSize(sizeButton);
    boton11->setIcon(buttonIcon);boton11->setIconSize(backCardIMage.rect().size());

    boton12->move(220,120);boton12->setFixedSize(sizeButton);
    boton12->setIcon(buttonIcon);boton12->setIconSize(backCardIMage.rect().size());

    boton13->move(320,120);boton13->setFixedSize(sizeButton);
    boton13->setIcon(buttonIcon);boton13->setIconSize(backCardIMage.rect().size());

    boton14->move(420,120);boton14->setFixedSize(sizeButton);
    boton14->setIcon(buttonIcon);boton14->setIconSize(backCardIMage.rect().size());

    boton15->move(520,120);boton15->setFixedSize(sizeButton);
    boton15->setIcon(buttonIcon);boton15->setIconSize(backCardIMage.rect().size());

    boton16->move(620,120);boton16->setFixedSize(sizeButton);
    boton16->setIcon(buttonIcon);boton16->setIconSize(backCardIMage.rect().size());

    boton17->move(720,120);boton17->setFixedSize(sizeButton);
    boton17->setIcon(buttonIcon);boton17->setIconSize(backCardIMage.rect().size());

    boton18->move(820,120);boton18->setFixedSize(sizeButton);
    boton18->setIcon(buttonIcon);boton18->setIconSize(backCardIMage.rect().size());

    boton19->move(920,120);boton19->setFixedSize(sizeButton);
    boton19->setIcon(buttonIcon);boton19->setIconSize(backCardIMage.rect().size());
/**
 * FILA3   FILA3   FILA3   FILA3   FILA3   FILA3   FILA3   FILA3   FILA3
 */
    boton20->move(20,220);boton20->setFixedSize(sizeButton);
    boton20->setIcon(buttonIcon);boton20->setIconSize(backCardIMage.rect().size());

    boton21->move(120,220);boton21->setFixedSize(sizeButton);
    boton21->setIcon(buttonIcon);boton21->setIconSize(backCardIMage.rect().size());

    boton22->move(220,220);boton22->setFixedSize(sizeButton);
    boton22->setIcon(buttonIcon);boton22->setIconSize(backCardIMage.rect().size());

    boton23->move(320,220);boton23->setFixedSize(sizeButton);
    boton23->setIcon(buttonIcon);boton23->setIconSize(backCardIMage.rect().size());

    boton24->move(420,220);boton24->setFixedSize(sizeButton);
    boton24->setIcon(buttonIcon);boton24->setIconSize(backCardIMage.rect().size());

    boton25->move(520,220);boton25->setFixedSize(sizeButton);
    boton25->setIcon(buttonIcon);boton25->setIconSize(backCardIMage.rect().size());

    boton26->move(620,220);boton26->setFixedSize(sizeButton);
    boton26->setIcon(buttonIcon);boton26->setIconSize(backCardIMage.rect().size());

    boton27->move(720,220);boton27->setFixedSize(sizeButton);
    boton27->setIcon(buttonIcon);boton27->setIconSize(backCardIMage.rect().size());

    boton28->move(820,220);boton28->setFixedSize(sizeButton);
    boton28->setIcon(buttonIcon);boton28->setIconSize(backCardIMage.rect().size());

    boton29->move(920,220);boton29->setFixedSize(sizeButton);
    boton29->setIcon(buttonIcon);boton29->setIconSize(backCardIMage.rect().size());
/**
* FILA4   FILA4   FILA4   FILA4   FILA4   FILA4   FILA4   FILA4   FILA4
*/
    boton30->move(20,320);boton30->setFixedSize(sizeButton);
    boton30->setIcon(buttonIcon);boton30->setIconSize(backCardIMage.rect().size());

    boton31->move(120,320);boton31->setFixedSize(sizeButton);
    boton31->setIcon(buttonIcon);boton31->setIconSize(backCardIMage.rect().size());

    boton32->move(220,320);boton32->setFixedSize(sizeButton);
    boton32->setIcon(buttonIcon);boton32->setIconSize(backCardIMage.rect().size());

    boton33->move(320,320);boton33->setFixedSize(sizeButton);
    boton33->setIcon(buttonIcon);boton33->setIconSize(backCardIMage.rect().size());

    boton34->move(420,320);boton34->setFixedSize(sizeButton);
    boton34->setIcon(buttonIcon);boton34->setIconSize(backCardIMage.rect().size());

    boton35->move(520,320);boton35->setFixedSize(sizeButton);
    boton35->setIcon(buttonIcon);boton35->setIconSize(backCardIMage.rect().size());

    boton36->move(620,320);boton36->setFixedSize(sizeButton);
    boton36->setIcon(buttonIcon);boton36->setIconSize(backCardIMage.rect().size());

    boton37->move(720,320);boton37->setFixedSize(sizeButton);
    boton37->setIcon(buttonIcon);boton37->setIconSize(backCardIMage.rect().size());

    boton38->move(820,320);boton38->setFixedSize(sizeButton);
    boton38->setIcon(buttonIcon);boton38->setIconSize(backCardIMage.rect().size());

    boton39->move(920,320);boton39->setFixedSize(sizeButton);
    boton39->setIcon(buttonIcon);boton39->setIconSize(backCardIMage.rect().size());
/**
* FILA5   FILA5   FILA5   FILA5   FILA5   FILA5   FILA5   FILA5   FILA5
*/
    boton40->move(20,420);boton40->setFixedSize(sizeButton);
    boton40->setIcon(buttonIcon);boton40->setIconSize(backCardIMage.rect().size());

    boton41->move(120,420);boton41->setFixedSize(sizeButton);
    boton41->setIcon(buttonIcon);boton41->setIconSize(backCardIMage.rect().size());

    boton42->move(220,420);boton42->setFixedSize(sizeButton);
    boton42->setIcon(buttonIcon);boton42->setIconSize(backCardIMage.rect().size());

    boton43->move(320,420);boton43->setFixedSize(sizeButton);
    boton43->setIcon(buttonIcon);boton43->setIconSize(backCardIMage.rect().size());

    boton44->move(420,420);boton44->setFixedSize(sizeButton);
    boton44->setIcon(buttonIcon);boton44->setIconSize(backCardIMage.rect().size());

    boton45->move(520,420);boton45->setFixedSize(sizeButton);
    boton45->setIcon(buttonIcon);boton45->setIconSize(backCardIMage.rect().size());

    boton46->move(620,420);boton46->setFixedSize(sizeButton);
    boton46->setIcon(buttonIcon);boton46->setIconSize(backCardIMage.rect().size());

    boton47->move(720,420);boton47->setFixedSize(sizeButton);
    boton47->setIcon(buttonIcon);boton47->setIconSize(backCardIMage.rect().size());

    boton48->move(820,420);boton48->setFixedSize(sizeButton);
    boton48->setIcon(buttonIcon);boton48->setIconSize(backCardIMage.rect().size());

    boton49->move(920,420);boton49->setFixedSize(sizeButton);
    boton49->setIcon(buttonIcon);boton49->setIconSize(backCardIMage.rect().size());

/**
* FILA6   FILA6   FILA6   FILA6   FILA6   FILA6   FILA6   FILA6   FILA6
*/
    boton50->move(20,520);boton50->setFixedSize(sizeButton);
    boton50->setIcon(buttonIcon);boton50->setIconSize(backCardIMage.rect().size());

    boton51->move(120,520);boton51->setFixedSize(sizeButton);
    boton51->setIcon(buttonIcon);boton51->setIconSize(backCardIMage.rect().size());

    boton52->move(220,520);boton52->setFixedSize(sizeButton);
    boton52->setIcon(buttonIcon);boton52->setIconSize(backCardIMage.rect().size());

    boton53->move(320,520);boton53->setFixedSize(sizeButton);
    boton53->setIcon(buttonIcon);boton53->setIconSize(backCardIMage.rect().size());

    boton54->move(420,520);boton54->setFixedSize(sizeButton);
    boton54->setIcon(buttonIcon);boton54->setIconSize(backCardIMage.rect().size());

    boton55->move(520,520);boton55->setFixedSize(sizeButton);
    boton55->setIcon(buttonIcon);boton55->setIconSize(backCardIMage.rect().size());

    boton56->move(620,520);boton56->setFixedSize(sizeButton);
    boton56->setIcon(buttonIcon);boton56->setIconSize(backCardIMage.rect().size());

    boton57->move(720,520);boton57->setFixedSize(sizeButton);
    boton57->setIcon(buttonIcon);boton57->setIconSize(backCardIMage.rect().size());

    boton58->move(820,520);boton58->setFixedSize(sizeButton);
    boton58->setIcon(buttonIcon);boton58->setIconSize(backCardIMage.rect().size());

    boton59->move(920,520);boton59->setFixedSize(sizeButton);
    boton59->setIcon(buttonIcon);boton59->setIconSize(backCardIMage.rect().size());

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

    ventana.show();
}

clienteMemoria::~clienteMemoria() {

}