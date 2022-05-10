#include "dddoctor.h"
#include "ui_dddoctor.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

void deletedwcno(QString dwcno,DDDoctor *ddd)
{
    QSqlQuery query;
    QString qstr = QString("select * from Doctor where dwcno = '%1'").arg(dwcno);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Doctor where dwcno = '%1'").arg(dwcno);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddd,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddd,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddd,"Error","未查询到相关信息，删除失败");
}
void deleteono(QString ono,DDDoctor *ddd)
{
    QSqlQuery query;
    QString qstr = QString("select * from Doctor where ono = '%1'").arg(ono);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Doctor where ono = '%1'").arg(ono);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddd,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddd,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddd,"Error","未查询到相关信息，删除失败");
}
void deletedname(QString dname,DDDoctor *ddd)
{
    QSqlQuery query;
    QString qstr = QString("select * from Doctor where dname = '%1'").arg(dname);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Doctor where dname = '%1'").arg(dname);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddd,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddd,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddd,"Error","未查询到相关信息，删除失败");
}

DDDoctor::DDDoctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DDDoctor)
{
    ui->setupUi(this);
    setWindowTitle("Delete in Doctor");
    connect(ui->btnDDoctor,&QPushButton::clicked,[=](){
        if(ui->cbDDoctor->currentIndex() == 0)
        {
            QString dwcno = ui->leDDoctor->displayText();
            deletedwcno(dwcno,this);
            ui->leDDoctor->setText("");
        }
        else if(ui->cbDDoctor->currentIndex() == 1)
        {
            QString ono = ui->leDDoctor->displayText();
            deleteono(ono,this);
            ui->leDDoctor->setText("");
        }
        else if(ui->cbDDoctor->currentIndex() == 2)
        {
            QString dname = ui->leDDoctor->displayText();
            deletedname(dname,this);
            ui->leDDoctor->setText("");
        }
    });
    connect(ui->btnDClose,&QPushButton::clicked,[=](){
        DDDoctor::close();
        });
}

DDDoctor::~DDDoctor()
{
    delete ui;
}



