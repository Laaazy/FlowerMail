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



void MainWindow::viewRecvedEmail()
{
    /*
        sendMessage("viewRecvedEmail");
        for(int i=0;i<10;i++){
            ui->email_1->setText(recvMessage());
        }
    */
}


void MainWindow::viewSendedEmail()
{
    /*
        sendMessage("viewSendedEmail");
        for(int i=0;i<10;i++){
            ui->email_1->setText(recvMessage());
        }
    */
}


void MainWindow::viewDeletedEmail()
{
    /*
        sendMessage("viewDeletedEmail");
        for(int i=0;i<10;i++){
            ui->email_1->setText(recvMessage());
        }
    */
}


void MainWindow::viewDaftEmail()
{
    /*
        sendMessage("viewDraftEmail");
        for(int i=0;i<10;i++){
            ui->email_1->setText(recvMessage());
        }
    */
}



void MainWindow::viewDetails()
{
    /*
        sendMessage("viewDetails");
        sendMessage(emailID);
        goto detail ui
        ui->sender->setText(recvMessage());
        ui->title->setText(recvMessage());
        ui->content->setText(recvMessage());
    */
}
