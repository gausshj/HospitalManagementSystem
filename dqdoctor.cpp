#include "dqdoctor.h"
#include "ui_dqdoctor.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidget>

void querydwcno(QString dwcno,DQDoctor *dqd)
{
    QSqlQuery query;
    QString str = QString("select * from Doctor where dwcno = '%1'").arg(dwcno);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Doctor");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(7);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"工作编号"<<"科室编号"<<"医生姓名"<<"医生年龄"<<"医生性别"<<"职称"<<"工资信息");
        qtw->setItem(0,0,new QTableWidgetItem(dwcno));
        for(int i = 1;i <7;i++)
        {
            QString strResult = query.value(i).toString();
            qtw->setItem(0,i,new QTableWidgetItem(strResult));
        }
        int width = qtw->frameGeometry().width();
        int height = qtw->frameGeometry().height();
        qdg->setFixedSize(width,height);
        //设置窗口居中
        qdg->move(qdg->geometry().center());
        qdg->exec();
        delete qdg;
    }
    else
    {
        QMessageBox::critical(dqd,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqd,"错误",Error);
    }
}
void queryono(QString ono,DQDoctor *dqd)
{
    QSqlQuery query;
    QString str = QString("select * from Doctor where ono = '%1'").arg(ono);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Doctor");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(7);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"工作编号"<<"科室编号"<<"医生姓名"<<"医生年龄"<<"医生性别"<<"职称"<<"工资信息");
        for(int i =0;i < query.numRowsAffected();i++)
        {
            for(int j=0 ;j < 7;j++)
            {
                QString strResult = query.value(j).toString();
                qtw->setItem(i,j,new QTableWidgetItem(strResult));
            }
            query.next();
        }
        int width = qtw->frameGeometry().width();
        int height = qtw->frameGeometry().height();
        qdg->setFixedSize(width,height);
        qdg->move(qdg->geometry().center());
        //设置窗口居中
        qdg->exec();
        delete qdg;
    }
    else
    {
        QMessageBox::critical(dqd,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqd,"错误",Error);
    }
}
void querydname(QString dname,DQDoctor *dqd)
{
    QSqlQuery query;
    QString str = QString("select * from Doctor where dname = '%1'").arg(dname);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Doctor");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(7);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"工作编号"<<"科室编号"<<"医生姓名"<<"医生年龄"<<"医生性别"<<"职称"<<"工资信息");
        for(int i =0;i < query.numRowsAffected();i++)
        {
            for(int j=0 ;j < 7;j++)
            {
                QString strResult = query.value(j).toString();
                qtw->setItem(i,j,new QTableWidgetItem(strResult));
            }
            query.next();
        }
        int width = qtw->frameGeometry().width();
        int height = qtw->frameGeometry().height();
        qdg->setFixedSize(width,height);
        qdg->move(qdg->geometry().center());
        //设置窗口居中
        qdg->exec();
        delete qdg;
    }
    else
    {
        QMessageBox::critical(dqd,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqd,"错误",Error);
    }
}
DQDoctor::DQDoctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DQDoctor)
{
    ui->setupUi(this);
    setWindowTitle("Query Doctor");
    connect(ui->btnQDoctor,&QPushButton::clicked,[=](){
        if(ui->cbDoctor->currentIndex() == 0)
        {
            //读取leQDoctor编辑栏中的文字
            QString dwcno = ui->leQDoctor->displayText();
            //调用函数查询
            querydwcno(dwcno,this);
            //使了编辑栏中的文字清零
            ui->leQDoctor->setText("");
        }
        else if(ui->cbDoctor->currentIndex() == 1)
        {
            QString ono = ui->leQDoctor->displayText();
            queryono(ono,this);
            ui->leQDoctor->setText("");
        }
        else if(ui->cbDoctor->currentIndex() == 2)
        {
            QString dname = ui->leQDoctor->displayText();
            queryono(dname,this);
            ui->leQDoctor->setText("");
        }
    });
    connect(ui->btnQClose,&QPushButton::clicked,[=](){
        DQDoctor::close();
    });
}

DQDoctor::~DQDoctor()
{
    delete ui;
}

