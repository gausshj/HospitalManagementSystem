#include "ddoffice.h"
#include "ui_ddoffice.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

void deleteono(QString ono,DDOffice *ddo)
{
    QSqlQuery query;
    QString qstr = QString("select * from Office where ono = '%1'").arg(ono);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Office where ono = '%1'").arg(ono);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddo,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddo,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddo,"Error","未查询到相关信息，删除失败");
}
void deleteoname(QString oname,DDOffice *ddo)
{
    QSqlQuery query;
    QString qstr = QString("select * from Office where oname = '%1'").arg(oname);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Office where oname = '%1'").arg(oname);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddo,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddo,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddo,"Error","未查询到相关信息，删除失败");
}
void deleteodno(QString odno,DDOffice *ddo)
{
    QSqlQuery query;
    QString qstr = QString("select * from Office where odno = '%1'").arg(odno);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Office where odno = '%1'").arg(odno);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddo,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddo,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddo,"Error","未查询到相关信息，删除失败");
}

DDOffice::DDOffice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DDOffice)
{
    ui->setupUi(this);
    setWindowTitle("Delete in Office");
    connect(ui->btnDOffice,&QPushButton::clicked,[=](){
        if(ui->cbDOffice->currentIndex() == 0)
        {
            QString ono = ui->leDOffice->displayText();
            deleteono(ono,this);
            ui->leDOffice->setText("");
        }
        else if(ui->cbDOffice->currentIndex() == 1)
        {
            QString oname = ui->leDOffice->displayText();
            deleteoname(oname,this);
            ui->leDOffice->setText("");
        }
        else if(ui->cbDOffice->currentIndex() == 2)
        {
            QString odno = ui->leDOffice->displayText();
            deleteodno(odno,this);
            ui->leDOffice->setText("");
        }
    });
    connect(ui->btnDClose,&QPushButton::clicked,[=](){
        DDOffice::close();
        });
}

DDOffice::~DDOffice()
{
    delete ui;
}




