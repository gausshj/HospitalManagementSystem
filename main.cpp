#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

//连接到SQLServer

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//数据库驱动类型sqlserver
    db.setHostName("(local)");//选择本地主机，或则127.0.0.1
    db.setDatabaseName("hospital");
    db.setUserName("sa");
    db.setPassword("1");
    if(!db.open())
    {
        qDebug()<<db.lastError().text();
        QMessageBox::critical(&w,"Informatinon",db.lastError().text());
    }
    else
    {
        qDebug()<<"database open success!";
        QMessageBox::information(&w,"Information","连接成功");
    }
    w.show();
    return a.exec();
}
