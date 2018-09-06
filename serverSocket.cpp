#include "serversocket.h"
#include <iostream>

#define SERVER_PORT 6666

Serversocket::Serversocket()
{
    //Initialize server
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVER_PORT);
    serveraddr.sin_addr.S_un.S_addr ="127.0.0.1" ;//???
    //serveraddr.sin_addr.S_un.S_addr = ADDR_ANY;
}

Serversocket::~Serversocket(){}

void Serversocket:: createSocketfd(){
    if( (socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        //exit(1);
    }
}

void Serversocket:: bindSocketfd(){
    if( bind(socket_fd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) == -1){
       printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
       //exit(1);
    }
}


void Serversocket:: listenSocketfd(){
    if( listen(socket_fd, 10) == -1){//???
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        //exit(1);
    }
}

void Serversocket::acceptSocketfd(){
    if((connectfd=accept(socketfd, (struct sockaddr*)NULL, NULL))==-1){//???
        printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
        //exit(1);
    }
}

void Serversocket::sendMsg(char *msg){
    if(send(connectfd, msg, sizeof(msg),0) == -1){
           perror("send error");
          //exit(1);
    }
}

void Serversocket::recvMsg(){
    if(recvNumber=recv(connectfd,buffer,BUFFER_SIZE,0)){
        perror("recv error");
        //exit(1);
    }
    else{
        buffer[recvNumber]='\0';
    }
}

void Serversocket::closeSocketfd(){
    close(socketfd);
}

void Serversocket::closeConnectfd(){
    close(connectfd);
}
