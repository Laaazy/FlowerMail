#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
Check UserID  only characters and shoter than length of 8
0:format wrong
1:ID already exist
2:right
*/
int MainWindow::checkUserID(){
    char userID[20]=ui->ID->text();//Remember to fix this!!!
    int len=strlen(usrID);
    if(len=0||len>8){
        //show warning window "ID length is illeagle!"
        return 0;
    }
    for(int i=0;i<len;i++){
        if((userID[i]>='a'&&userID[i]<='z')||(userID[i]>='A'&&userID[i]<='Z'))
            continue;
        else{
            //show warning window "Illeague ID!"
            return 0;
        }
    }
    /*
        sendMessage("checkUserID");
        sendMessage("userID");
        if(recvMessage().equals("exist")){
            show warning window "ID already exists!"
            return 1;
        }
    */
    return 2;
}



/*
Check PassWord:PassWord length must >=6 and <= 10
0:length wrong
1:diferrent in confirm
2:right
*/
int MainWindow::checkPassWord()
{
    char passWord[20]=ui->Password->text();//Remember to fix this!!!
    char confirm[20]=ui->confirm->text();//Remember to fix this!!!
    int len=strlen(passWord);
    if(len<6||len>10){
        //show warning window "Illeague length!"
        return 0;
    }
    if(!strcmp(confirm,passWord)){
        //show warning window "Different in confirm!"
        return 1;
    }
    return 2;
}



/*
Register reslut
0:wrong
1:right
*/
int MainWindow::check()
{
    if((checkUserID()==2)&&(checkPassWord()==2))
        return 1;
    else
        return 0;
}




/*
Check PassWord:PassWord length must >=6 and <= 10
0:right
1:wrong
*/
void MainWindow::Register()
{
    if(check()){
        /*use client`s send() to tell server a new account will be created,
         * then use send() to send UserID and PassWord to server
           sendMessage("register");
           sendMessage(ui->userID->text());
           sendMessage(ui->passWord->text());
           if(recvMeassage().equals("right")){
                goto main UI;
            }
         */
    }

}
