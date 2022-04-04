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
#include <QApplication>
#include<thread>
// https://www.youtube.com/watch?v=61d3GhuxgUk&t=0s

//https://github.com/SebastianRiquelmeM/Socket-C-Class-Server/blob/master/Servidor%20%20Por%20Sebasti%C3%A1n%20Riquelme..cpp
using namespace std;
/**
void guiServerThread(){
    new guiServer;
}
**/
class Client{
public:
    struct sockaddr_in addr;
    char buffer[1024];
    int server;
    Client()
    {
        cout<<"Conectando al servidor..."<<endl<<endl;
        // WSAStartup(MAKEWORD(2,0), &WSAData);
        server = socket(AF_INET, SOCK_STREAM, 0);
        addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        addr.sin_family = AF_INET;
        addr.sin_port = htons(PORT);
        connect(server,(struct sockaddr *)&addr, sizeof(addr));
        cout << "Conectado al Servidor!" << endl;
    }
    void Enviar()
    {
        cout<<"Escribe el mensaje a enviar: ";
        cin>>this->buffer;
        send(server, buffer, sizeof(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
        cout << "Mensaje enviado!" << endl;
    }
    void Recibir()
    {
        recv(server, buffer, sizeof(buffer), 0);
        cout << "El servidor dice: " << buffer << endl;
        memset(buffer, 0, sizeof(buffer));
    }
    void CerrarSocket()
    {
        close(server);
        //WSACleanup();
        cout << "Socket cerrado." << endl << endl;
    }
};

int main()
{
    Client *Cliente = new Client();
    while(true)
    {
        Cliente->Enviar();

        Cliente->Recibir();

    }
}


