#include "server.h"

Server::Server()
{

}

Server::~Server(){

}


/*
    switch(server.recvMsg()){
        case:"checkUserID":{
            checkUserID();
            break;
        }
        case:"register":{
            register();
            break;
        }
        case:"login":{
            login();
            break;
        }
        case:"clientSendEmail":{
            clientSendEmail();
            break;
        }
        case:"viewRecvedEmail"{
            viewRecvedEmail();
            break;
        }
        case:"viewSendedEmail"{
            viewSendedEmail();
            break;
        }
        case:"viewDeletedEmail"{
            viewDeletedEmail();
            break;
        }
        case:"viewDraftEmail"{
            viewDraftedEmail();
            break;
        }
        case:"viewDetails"{
            viewDetails();
            break;
        }
        default:
    }
*/

/*
void checkUserID(){
        char userID[20]=server.recvMsg();
        if(checkUserIDInMysql("userID")=="exist"){
            server.sendMsg("exist");
        }
        else{
            server.sendMsg("OK");
        }
}
*/

/*
void register(){
    char newUserID[20]=server.recvMsg();
    char newPassWord[20]=server.recvMsg();
    store newUserID and newPassWord in Mysql;
}
*/

/*
void login(){
    char userID[20]=server.recvMsg();
    char passWord[20]=server.recvMsg();
    if(check userID and passWord in Mysql=="OK"){
        server.sendMsg("correct");
    }
    else{
        server.sendMsg("not correct");
    }
}
*/

/*
void clientSendEmail(){
    if(char sender[20]=server.recvMsg()){
        server.sendMsg("OK");
        if(char title[20]=server.recvMsg()){
            server.sendMsg("OK");
            if(char content[1000]=server.recvMsg()){
                server.sendMsg("OK");
            }
            else{
                server.sendMsg("false");
            }
        }
        else{
            server.sendMsg("false");
        }
    }
    else{
        server.sendMsg("false");
    }
    store sender  title  content in Mysql
}
*/

/*
void viewRecvedEmail(){
    for(email in Mysql){
        if(email == new email){
            char giveBack[50]=Mysql`giveBack;
            server.sendMsg(giveBack);
        }
    }
*/

/*
void viewSendedEmail(){
    for(email in Mysql){
        if(email == sended email){
            char giveBack[50]=Mysql`giveBack;
            server.sendMsg(giveBack);
        }
    }
*/

/*
void viewDeletedEmail(){
    for(email in Mysql){
        if(email == Deleted email){
            char giveBack[50]=Mysql`giveBack;
            server.sendMsg(giveBack);
        }
    }
*/

/*
void viewDraftEmail(){
    for(email in Mysql){
        if(email == Draft email){
            char giveBack[50]=Mysql`giveBack;
            server.sendMsg(giveBack);
        }
    }
*/

/*
void viewDetails(){
    char emailID[20]=server.recvMsg();
    Mysql check the details of email and give back three srings which are sender title content
    for(email in Mysql){
        if(OneEmailID ==emailID ){
            char sender[20]=Mysql_eamilID.sender;
            char title[20]=Mysql_eamilID.title;
            char content[20]=Mysql_eamilID.content;
            server.sendMsg(sender);
            server.sendMsg(title);
            server.sendMsg(content);
        }
    }
}
*/
