#include "guiCliente.h"
#include <QApplication>
using namespace std;
void ciclo(guiCliente gui){

    while(true)
    {
        gui.Enviar();
        gui.Recibir();}

}
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    guiCliente *GUI = new guiCliente();
    printf("Hola");
    GUI->Client();
    GUI->interfaz();
    //std::thread loop(ciclo(GUI));
    return app.exec();
}
