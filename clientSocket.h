#ifndef CLIENT_H
#define CLIENT_H
#define MAXLENGTH 10000
#define RECVMAXLENGTH 10000

#include <QObject>
//#include<QDebug>
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

class Client
{

public:
    Client();
    ~Client();

    void connectServer();
    void sendMsg(char* msg);
    char *recvMsg();
    void disconnect();
    void sendFile(char *filePath);
    void recvFile(char *msg);

private:
    QString ipAddress;
    int socketfd;
    int fileLen;
    char recvMessage[MAXLENGTH];
    char fileContent[MAXLENGTH];//File content buffer
    FILE *fp;
    int recvLen;
    sockaddr_in servaddr;
    int flag;//while send file

};

#endif // CLIENT_H
