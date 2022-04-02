#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#define PORT 8080
#include <netdb.h>
#include "guiCliente.h"
#include "guiPrueba.cpp"
#include <QApplication>
#include<thread>
// https://www.youtube.com/watch?v=61d3GhuxgUk&t=0s
using namespace std;
/**
void guiServerThread(){
    new guiServer;
}
**/
class Client{
public:
    struct sockaddr_in server_addr;
    char buffer[1024];
    int client;
    Client()
    {
        cout<<"Conectando al servidor..."<<endl<<endl;
       // WSAStartup(MAKEWORD(2,0), &WSAData);
        client = socket(AF_INET, SOCK_STREAM, 0);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);
        connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr));
        cout << "Conectado al Servidor!" << endl;
    }
    void Enviar()
    {
        cout<<"Escribe el mensaje a enviar: ";
        cin>>this->buffer;
        send(client, buffer, sizeof(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
        cout << "Mensaje enviado!" << endl;
    }
    void Recibir()
    {
        recv(client, buffer, sizeof(buffer), 0);
        cout << "El servidor dice: " << buffer << endl;
        memset(buffer, 0, sizeof(buffer));
    }
    void CerrarSocket()
    {
        close(client);
        //WSACleanup();
        cout << "Socket cerrado." << endl << endl;
    }
};

int main(int argc, char *argv[])
{
    Client *Cliente = new Client();
    QApplication app(argc, argv);
    guiCliente *GUI = new guiCliente();
    GUI->interfaz();
    while(true)
    {
        GUI->isHidden();
        Cliente->Enviar();
        Cliente->Recibir();
    }
}

/**
int main(int argc, char *argv[]){
//int main(){
    /**
    QApplication app(argc, argv);
    std::thread hilo(& guiServerThread);
    hilo.join();
    //thread th(guiServerThread());

    QApplication app(argc, argv);
    int portNum = 1080; // NOTE that the port number is same for both client and server
    bool isExit = false;
    //int bufsize = 1024;
    //char buffer[1024] = {0};
    char *ip = ;
    guiCliente *GUI = new guiCliente;

    struct sockaddr_in server_addr;


    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    /* --------------- socket() function ------------------*/
/****
 * XXXXXXXXXXXXXXXXXXXXX
 * XXXXXXXXXXXXXXXXXXXXX

    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) < 0)
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

    cout << "\n=> Socket client has been created..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    /* ---------- CONNECTING THE SOCKET ----------
    /* ---------------- connect() ----------------
    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0){
    //guiCliente::paintingActive();
        GUI->show();

        cout << "=> Connection to the server port number: " << portNum << endl;


    cout << "=> Awaiting confirmation from the server..." << endl; //line 40
    recv(client, buffer, bufsize, 0);
    cout << "=> Connection confirmed, you are good to go...";

    cout << "\n\n=> Enter # to end the connection\n" << endl;

    // Once it reaches here, the client can send a message first.

    do {

        cout << "Client: ";
        do {
            cin >> buffer;
            send(client, buffer, bufsize, 0);
            if (*buffer == '#') {
                send(client, buffer, bufsize, 0);
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != 42);

        cout << "Server: ";
        do {
            recv(client, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }

        } while (*buffer != 42);
        cout << endl;


    } while (!isExit);

    }
    cout << "\n=> Connection terminated.\nGoodbye...\n";

//    return 0;
    return app.exec();

}
**/