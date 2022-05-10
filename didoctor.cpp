#include "didoctor.h"
#include "ui_didoctor.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

QStringList DIDoctor::setleEText(QString dwcno)
{
    ui->btnIDoctor->setText("修改");
    QStringList dlist;
    QSqlQuery query;
    QString str = QString("select * from Doctor where dwcno = '%1'").arg(dwcno);
    query.exec(str);
    if(query.next())
    {
        QString mdwcno = query.value(0).toString();
        QString mono = query.value(1).toString();
        QString mdname = query.value(2).toString();
        QString mdage = query.value(3).toString();
        QString mdsex = query.value(4).toString();
        QString mdtitle = query.value(5).toString();
        QString mdsalary = query.value(6).toString();
        dlist<<mdwcno<<mono<<mdname<<mdage<<mdsex<<mdtitle<<mdsalary;
        ui->leIdwcno->setText(mdwcno);
        ui->leIono->setText(mono);
        ui->leIdname->setText(mdname);
        ui->leIdage->setText(mdage);
        ui->leIdsex->setText(mdsex);
        ui->leIdtitle->setText(mdtitle);
        ui->leIdsalary->setText(mdsalary);
    }
    else
    {
        QMessageBox::critical(this,"错误","未查询到相关信息");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(this,"错误",Error);
    }
    return dlist;
}

QStringList DIDoctor::readleEText()
{
    QString dwcno = ui->leIdwcno->displayText();
    QString ono = ui->leIono->displayText();
    QString dname = ui->leIdname->displayText();
    QString dage = ui->leIdage->displayText();
    QString dsex = ui->leIdsex->displayText();
    QString dtitle = ui->leIdtitle->displayText();
    QString dsalary = ui->leIdsalary->displayText();
    QStringList mdlist;
    mdlist<<dwcno<<ono<<dname<<dage<<dsex<<dtitle<<dsalary;
    return mdlist;
}

void DIDoctor::setconnect()
{

}

QString insertDoctor(QString dwcno,QString ono,QString dname,int dage,QString dsex,QString dtitle,int dsalary)
{
    QString str = QString("insert into Doctor values('%1','%2','%3',%4,'%5','%6',%7)")
            .arg(dwcno).arg(ono).arg(dname).arg(dage).arg(dsex).arg(dtitle).arg(dsalary);
    QSqlQuery query;//构建对象query
    query.exec(str);
    return query.lastError().text();
}

DIDoctor::DIDoctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DIDoctor)
{
    ui->setupUi(this);
    setWindowTitle("Insert Doctor");
    connect(ui->btnIDoctor,&QPushButton::clicked,[=](){
        //读取文字框中的内容
        QString dwcno = ui->leIdwcno->displayText();
        QString ono = ui->leIono->displayText();
        QString dname = ui->leIdname->displayText();
        int dage = ui->leIdage->displayText().toInt();
        QString dsex = ui->leIdsex->displayText();
        QString dtitle = ui->leIdtitle->displayText();
        int dsalary = ui->leIdsalary->displayText().toInt();
        //清空lineedit中的文字
        ui->leIdwcno->setText("");
        ui->leIono->setText("");
        ui->leIdname->setText("");
        ui->leIdage->setText("");
        ui->leIdsex->setText("");
        ui->leIdtitle->setText("");
        ui->leIdsalary->setText("");
        QString Error = insertDoctor(dwcno,ono,dname,dage,dsex,dtitle,dsalary);
        if(Error == " ")
        {
            QMessageBox::information(this,"信息","保存成功");
        }
        else
            QMessageBox::critical(this,"错误",Error);
    });
    connect(ui->btnIClose,&QPushButton::clicked,[=](){
        DIDoctor::close();
    });
}

DIDoctor::~DIDoctor()
{
    delete ui;
}

