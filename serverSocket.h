#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include<QString>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>

#define BUFFER_SIZE 10000



class Serversocket
{
public:
    Serversocket();
    ~Serversocket();

    int socketfd;
    int connectfd;
    int recvNumber;
    struct sockaddr serveraddr;
    char buffer[10000];

    void createSocketfd(){}
    void bindSocketfd(){}
    void listenSocketfd(){}
    void acceptSocketfd(){}
    void sendMsg(char *msg){}
    void recvMsg(){}
    void closeSocketfd(){}
    void closeConnectfd(){}
private:
};

#endif
