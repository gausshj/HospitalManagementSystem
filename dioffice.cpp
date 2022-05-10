#include "dioffice.h"
#include "ui_dioffice.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

QString insertOffice(QString ono,QString oname,QString oadd,QString otel,QString odno)
{
    QString str = QString("insert into Office values('%1','%2','%3','%4','%5')")
            .arg(ono).arg(oname).arg(oadd).arg(otel).arg(odno);
    QSqlQuery query;//构建对象query
    query.exec(str);
    return query.lastError().text();
}

DIOffice::DIOffice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DIOffice)
{
    ui->setupUi(this);
    setWindowTitle("Insert Office");
    connect(ui->btnIOffice,&QPushButton::clicked,[=](){
        //读取文字框中的内容
        QString ono = ui->leIono->displayText();
        QString oname = ui->leIoname->displayText();
        QString oadd = ui->leIoadd->displayText();
        QString otel = ui->leIotel->displayText();
        QString odno = ui->leIodno->displayText();
        //清空lineedit中的文字
        ui->leIono->setText("");
        ui->leIoname->setText("");
        ui->leIoadd->setText("");
        ui->leIotel->setText("");
        ui->leIodno->setText("");
        QString Error = insertOffice(ono,oname,oadd,otel,odno);
        if(Error == " ")
        {
            QMessageBox::information(this,"信息","保存成功");
        }
        else
            QMessageBox::critical(this,"错误",Error);
    });
    connect(ui->btnIClose,&QPushButton::clicked,[=](){
        DIOffice::close();
    });
}

DIOffice::~DIOffice()
{
    delete ui;
}






