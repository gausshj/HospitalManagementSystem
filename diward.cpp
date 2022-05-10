#include "diward.h"
#include "ui_diward.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

QString insertWard(QString wno,QString ono,QString wadd)
{
    QString str = QString("insert into Ward values('%1','%2','%3')")
            .arg(wno).arg(ono).arg(wadd);
    QSqlQuery query;//构建对象query
    query.exec(str);
    return query.lastError().text();
}

DIWard::DIWard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DIWard)
{
    ui->setupUi(this);
    setWindowTitle("Insert Ward");
    connect(ui->btnIWard,&QPushButton::clicked,[=](){
        //读取文字框中的内容
        QString wno = ui->leIwno->displayText();
        QString ono = ui->leIono->displayText();
        QString wadd = ui->leIwadd->displayText();
        //清空lineedit中的文字
        ui->leIwno->setText("");
        ui->leIono->setText("");
        ui->leIwadd->setText("");
        QString Error = insertWard(wno,ono,wadd);
        if(Error == " ")
        {
            QMessageBox::information(this,"信息","保存成功");
        }
        else
            QMessageBox::critical(this,"错误",Error);
    });
    connect(ui->btnIClose,&QPushButton::clicked,[=](){
        DIWard::close();
    });
}

DIWard::~DIWard()
{
    delete ui;
}







