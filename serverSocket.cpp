#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QDebug"
#include "QString"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QString("服务器"));
    //服务器参数初始化
    server = new QTcpServer();//初始化QTcpServer对象

    //当服务器被客户端访问时，会触发newConnection信号，可以利用该信号作为触发信号，绑定槽函数Server_New_Connect
    connect(server,&QTcpServer::newConnection,this,&MainWindow::server_New_Connect);
    ui->lineEdit_IP->setText("172.20.10.2");//设置默认
    ui->lineEdit_Port->setText("6666");//设置默认端口号
}

MainWindow::~MainWindow()
{
    server->close();
    server->deleteLater();

    delete ui;
}

void MainWindow::on_pushButton_Listen_clicked()
{
    //侦听一个端口，客户端可以使用这个端口访问服务器
    QHostAddress IP(ui->lineEdit_IP->text());
    quint16 port = ui->lineEdit_Port->text().toUInt();
    if(server->listen(IP,port))
    {
        //监听成功
    }
    else
    {
        //监听失败
        QMessageBox::warning(this,"warning",tr("监听失败"),QMessageBox::Yes,QMessageBox::No);
    }
}



void MainWindow::on_pushButton_Send_clicked()
{
    qint64 writeResult = socket->write(ui->textEdit_Send->toPlainText().toLatin1());
    bool BoolFlush = socket->flush();//从缓冲区读写数据，如果从缓冲区读写了数据，则返回true；否则返回false
    if(writeResult != -1 && BoolFlush == 1)
    {
        //writeResult不为-1 且 BoolFLush为1时则发送成功
        if(writeResult == 0)
        {
            QMessageBox::warning(this,"warning",tr("写数据结果返回值为0"),QMessageBox::Yes,QMessageBox::No);
        }
        QMessageBox::warning(this,"warning",tr("写数据成功！"),QMessageBox::Yes,QMessageBox::No);
    }
}


void MainWindow::server_New_Connect()
{
    //获取客户端连接
    socket = server->nextPendingConnection();

    //连接QTcpSocket的信号槽，以读取新数据
    //&QTcpSocket::readyRead表示服务器接收到客户端数据后，自动触发readyRead信号
    //&QTcpSocket::disconnected表示服务器接收到客户端断开连接后，自动触发
    QObject::connect(socket,&QTcpSocket::readyRead,this,&MainWindow::socket_Read_Data);
    QObject::connect(socket,&QTcpSocket::disconnected,this,&MainWindow::socket_Disconnect);

}


void MainWindow::socket_Read_Data()
{
    QByteArray buffer;
    buffer = socket->readAll();//读取缓冲区数据
    ui->textEdit_Receive->setText(buffer);

}

void MainWindow::socket_Disconnect()
{
    //
}
