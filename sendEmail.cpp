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

void MainWindow::sendMail()
{
    char sender[20]=ui->sender->toPlainText();
    char title[20]=ui->title->toPlainText();
    char content[1000]=ui->content->toPlainText();
    /*
        sendMessage("clientSendEmail");
        sendMessage(sender);
        if(recvMessage().equals("OK")){
            sendMessage(title);
            if(recvMessage().equals("OK")){
                sendMessgae(content);
                if(recvMessage().equals("OK")){
                    show tip window  "Send email succeed!";
                }
            }
            else{
                printf("title missed!\n");
            }
        }
        else{
            printf("sender missed!\n");
        }
    */
}
