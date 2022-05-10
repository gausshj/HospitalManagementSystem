#include "dmdoctor.h"
#include "ui_dmdoctor.h"
#include "didoctor.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

DMDoctor::DMDoctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DMDoctor)
{
    ui->setupUi(this);
    connect(ui->btnNext,&QPushButton::clicked,[=](){
        QString dwcno = ui->leDoctor->displayText();
        if(dwcno.isEmpty())
        {
            QMessageBox::critical(this,"错误","请输入内容后查询");
        }
        else
        {
            DIDoctor *did = new DIDoctor(this);
            did->show();
            QStringList dlist = did->setleEText(dwcno);
            QStringList mdlist = did->readleEText();
        }
        ui->leDoctor->setText("");
    });
    connect(ui->btnClose,&QPushButton::clicked,[=](){
        DMDoctor::close();
    });

}

DMDoctor::~DMDoctor()
{
    delete ui;
}
