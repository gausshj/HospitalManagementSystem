#include "ddpatient.h"
#include "ui_ddpatient.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

void deletepmrno(QString pmrno,DDPatient *ddp)
{
    QSqlQuery query;
    QString qstr = QString("select * from Patient where pmrno = '%1'").arg(pmrno);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Patient where pmrno = '%1'").arg(pmrno);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddp,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddp,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddp,"Error","未查询到相关信息，删除失败");
}
void deleteono(QString ono,DDPatient *ddp)
{
    QSqlQuery query;
    QString qstr = QString("select * from Patient where ono = '%1'").arg(ono);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Patient where ono = '%1'").arg(ono);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddp,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddp,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddp,"Error","未查询到相关信息，删除失败");
}
void deletedwcno(QString dwcno,DDPatient *ddp)
{
    QSqlQuery query;
    QString qstr = QString("select * from Patient where dwcno = '%1'").arg(dwcno);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Patient where dwcno = '%1'").arg(dwcno);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddp,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddp,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddp,"Error","未查询到相关信息，删除失败");
}
void deletepname(QString pname,DDPatient *ddp)
{
    QSqlQuery query;
    QString qstr = QString("select * from Patient where pname = '%1'").arg(pname);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Patient where pname = '%1'").arg(pname);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddp,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddp,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddp,"Error","未查询到相关信息，删除失败");
}

DDPatient::DDPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DDPatient)
{
    ui->setupUi(this);
    setWindowTitle("Delete in Patient");
    connect(ui->btnDPatient,&QPushButton::clicked,[=](){
        if(ui->cbDPatient->currentIndex() == 0)
        {
            QString pmrno = ui->leDPatient->displayText();
            deletepmrno(pmrno,this);
            ui->leDPatient->setText("");
        }
        else if(ui->cbDPatient->currentIndex() == 1)
        {
            QString dwcno = ui->leDPatient->displayText();
            deletedwcno(dwcno,this);
            ui->leDPatient->setText("");
        }
        else if(ui->cbDPatient->currentIndex() == 2)
        {
            QString ono = ui->leDPatient->displayText();
            deleteono(ono,this);
            ui->leDPatient->setText("");
        }
        else if(ui->cbDPatient->currentIndex() == 3)
        {
            QString pname = ui->leDPatient->displayText();
            deletepname(pname,this);
            ui->leDPatient->setText("");
        }
    });
    connect(ui->btnDClose,&QPushButton::clicked,[=](){
        DDPatient::close();
        });
}

DDPatient::~DDPatient()
{
    delete ui;
}



