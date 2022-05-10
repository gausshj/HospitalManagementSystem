#include "dipatient.h"
#include "ui_dipatient.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

QString insertPatient(QString pmrno,QString ono,QString dwcno,QString pname,QString psex,QString pag,QString pdoa,QString pdod)
{
    QString str = QString("insert into Patient values('%1','%2','%3','%4','%5','%6','%7','%8')")
            .arg(pmrno).arg(ono).arg(dwcno).arg(pname).arg(psex).arg(pag).arg(pdoa).arg(pdod);
    QSqlQuery query;//构建对象query
    query.exec(str);
    return query.lastError().text();
}

DIPatient::DIPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DIPatient)
{
    ui->setupUi(this);
    setWindowTitle("Insert Patient");
    connect(ui->btnIPatient,&QPushButton::clicked,[=](){
        //读取文字框中的内容
        QString pmrno = ui->leIpmrno->displayText();
        QString ono = ui->leIono->displayText();
        QString dwcno = ui->leIdwcno->displayText();
        QString pname = ui->leIpname->displayText();
        QString psex = ui->leIpsex->displayText();
        QString pag = ui->leIpag->displayText();
        QString pdoa = ui->leIpdoa->displayText();
        QString pdod = ui->leIpdod->displayText();
        //清空lineedit中的文字
        ui->leIpmrno->setText("");
        ui->leIono->setText("");
        ui->leIdwcno->setText("");
        ui->leIpname->setText("");
        ui->leIpsex->setText("");
        ui->leIpag->setText("");
        ui->leIpdoa->setText("");
        ui->leIpdod->setText("");
        QString Error = insertPatient(pmrno,ono,dwcno,pname,psex,pag,pdoa,pdod);
        if(Error == " ")
        {
            QMessageBox::information(this,"信息","保存成功");
        }
        else
            QMessageBox::critical(this,"错误",Error);
    });
    connect(ui->btnIClose,&QPushButton::clicked,[=](){
        DIPatient::close();
    });
}

DIPatient::~DIPatient()
{
    delete ui;
}







