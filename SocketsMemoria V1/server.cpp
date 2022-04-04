#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#define PORT 8080
//#include "serverGUI.h"

using namespace std;

class Server{
public:
    int server, client;
    int bufsize = 1024;
    char buffer[1024];

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t size;
    Server()
    {
        //WSAStartup(MAKEWORD(2,0), &WSAData);
        server = socket(AF_INET, SOCK_STREAM, 0);

        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);

        bind(server, (sockaddr *)&server_addr, sizeof(server_addr));
        listen(server, 0);

        cout << "Escuchando para conexiones entrantes." << endl;
        size = sizeof(client_addr);
        //    server = accept(client,(struct sockaddr *)&server_addr,&size);
        //int prueba = (client = accept(server, (struct sockaddr *)&clientAddr, &clientAddrSize));
        //        if((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize)) != INVALID_SOCKET)
        //server = accept(client,(struct sockaddr *)&serverAddr,&size);

        //client = accept(server,(struct sockaddr *)&client_addr,&size);
        if(client = accept(server,( sockaddr *)&client_addr,&size)){
            cout << "Cliente conectado!" << endl;
        }
    }

    void Recibir()
    {
        //                recv(server, buffer, bufsize, 0);
        recv(client, buffer, sizeof(buffer), 0);
        cout << "El cliente dice: " << buffer << endl;
        memset(buffer, 0, sizeof(buffer));
    }
    void Enviar()
    {
        cout<<"Escribe el mensaje a enviar: ";
        cin>>this->buffer;
        send(client, buffer, sizeof(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
        cout << "Mensaje enviado!" << endl;
    }
    void CerrarSocket()
    {
        close(server);
        cout << "Socket cerrado, cliente desconectado." << endl;
    }
};


int main()
{
    Server *Servidor = new Server();
    while(true)
    {
        Servidor->Recibir();

        Servidor->Enviar();


    }
}