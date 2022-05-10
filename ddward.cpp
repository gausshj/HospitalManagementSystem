#include "ddward.h"
#include "ui_ddward.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

void deletewno(QString wno,DDWard *ddw)
{
    QSqlQuery query;
    QString qstr = QString("select * from Ward where wno = '%1'").arg(wno);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Ward where wno = '%1'").arg(wno);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddw,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddw,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddw,"Error","未查询到相关信息，删除失败");
}
void deleteono(QString ono,DDWard *ddw)
{
    QSqlQuery query;
    QString qstr = QString("select * from Ward where ono = '%1'").arg(ono);
    query.exec(qstr);
    if(query.numRowsAffected() > 0)
    {
        QString dstr;
        dstr=QString("delete from Ward where ono = '%1'").arg(ono);
        query.exec(dstr);
        if(query.lastError().text() == " ")
            QMessageBox::information(ddw,"Notice","Delete sucessful!");
        else
            QMessageBox::critical(ddw,"Error",query.lastError().text());
    }
    else
        QMessageBox::critical(ddw,"Error","未查询到相关信息，删除失败");
}

DDWard::DDWard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DDWard)
{
    ui->setupUi(this);
    setWindowTitle("Delete in Ward");
    connect(ui->btnDWard,&QPushButton::clicked,[=](){
        if(ui->cbDWard->currentIndex() == 0)
        {
            QString wno = ui->leDWard->displayText();
            deletewno(wno,this);
            ui->leDWard->setText("");
        }
        else if(ui->cbDWard->currentIndex() == 1)
        {
            QString ono = ui->leDWard->displayText();
            deleteono(ono,this);
            ui->leDWard->setText("");
        }
    });
    connect(ui->btnDClose,&QPushButton::clicked,[=](){
        DDWard::close();
        });
}

DDWard::~DDWard()
{
    delete ui;
}




