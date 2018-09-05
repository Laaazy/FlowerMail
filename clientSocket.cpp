#include "client.h"

Client::Client()
{
    this->ipAddress="127.0.0.1";
    this->socketfd=socket(AF_INET,SOCK_STREAM,0);
    if(socketfd<0){
        perror("Create socket error");
        //printf("Create socket error: %s(errno: %d)\n", strerror(errno),errno);
        exit(1);
    }
    else
        printf("Create socket succeed!\n");

    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(6666);
    //servaddr.sin_addr.s_addr = inet_addr("10.62.62.245");
   if(inet_pton(AF_INET, "172.20.10.2", &servaddr.sin_addr)<=0){//Remember to fix this while use
       perror("inet_pton error");
       //printf("inet_pton error for %s\n","10.62.62.245");
        exit(1);
    }
    else{
        printf("inet_pton succeed!\n");
        //printf("%ld\n",servaddr.sin_addr.s_addr);
    }
}

Client::~Client(){}

void Client::connectServer(){
    if(connect(socketfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0){
        perror("Connect server error");
        //printf("Connect server error: %s(errno: %d)\n", strerror(errno),errno);
        exit(0);
    }
    else
        printf("Connect server succeed!\n");
}

void Client::sendMsg(char* msg){
    if(send(socketfd,msg,strlen(msg),0)<0){
        perror("Send message error");
        //printf("Send message error: %s(errno: %d)\n", strerror(errno),errno);
        exit(0);
    }
    else
        printf("Send message succeed!\n");
}

char* Client::recvMsg(){
    recvLen=recv(socketfd,recvMessage,MAXLENGTH,0);
    if(recvLen==-1){
        perror("Receive message error");
        //printf("Receive message error: %s(errno: %d)\n", strerror(errno),errno);
        exit(1);
    }
    else{
        recvMessage[recvLen]='\0';
        printf("Receive message succeed!\n");
    }
    return recvMessage;
}

void Client::disconnect(){
    close(socketfd);
}

void Client::sendFile(char *filePath){
    flag=0;
    bzero(fileContent,sizeof(fileContent));
    if((fp= fopen(filePath,"r"))== NULL)
    {
     perror("File open failed");
     close(socketfd);
     exit(1);
    }
    while (!feof(fp)) {
        fileLen=fread(fileContent,sizeof(char),RECVMAXLENGTH,fp);
        printf("%s\n",fileContent);
        if(fileLen!=send(socketfd,fileContent,fileLen,0)){
            perror("Send file failed");
            flag=1;
            break;
        }
    }
    fclose(fp);
    if(flag==0){
        printf("Send file succeed!\n");
    }
}

void Client::recvFile(char *msg){

}
