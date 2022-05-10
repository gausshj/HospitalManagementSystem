#include "dqpatient.h"
#include "ui_dqpatient.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidget>

void querypmrno(QString pmrno,DQPatient *dqp)
{
    QSqlQuery query;
    QString str = QString("select * from Patient where pmrno = '%1'").arg(pmrno);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Patient");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(8);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"病历号"<<"科室编号"<<"工作编号"<<"病人姓名"<<"病人性别"<<"病人年龄"<<"入院日期"<<"出院日期");
        qtw->setItem(0,0,new QTableWidgetItem(pmrno));
        for(int i = 1;i < 8;i++)
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
        QMessageBox::critical(dqp,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqp,"错误",Error);
    }
}
void queryono(QString ono,DQPatient *dqp)
{
    QSqlQuery query;
    QString str = QString("select * from Patient where ono = '%1'").arg(ono);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Patient");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(8);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"病历号"<<"科室编号"<<"工作编号"<<"病人姓名"<<"病人性别"<<"病人年龄"<<"入院日期"<<"出院日期");
        for(int i =0;i < query.numRowsAffected();i++)
        {
            for(int j=0 ;j < 8;j++)
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
        QMessageBox::critical(dqp,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqp,"错误",Error);
    }
}
void querydwcno(QString dwcno,DQPatient *dqp)
{
    QSqlQuery query;
    QString str = QString("select * from Patient where dwcno = '%1'").arg(dwcno);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Patient");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(8);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"病历号"<<"科室编号"<<"工作编号"<<"病人姓名"<<"病人性别"<<"病人年龄"<<"入院日期"<<"出院日期");
        for(int i = 0;i < query.numRowsAffected();i++)
        {
            for(int j = 0 ;j < 8;j++)
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
        QMessageBox::critical(dqp,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqp,"错误",Error);
    }
}
void querypname(QString pname,DQPatient *dqp)
{
    QSqlQuery query;
    QString str = QString("select * from Patient where pname = '%1'").arg(pname);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Patient");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(8);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"病历号"<<"科室编号"<<"工作编号"<<"病人姓名"<<"病人性别"<<"病人年龄"<<"入院日期"<<"出院日期");
        for(int i = 0;i < query.numRowsAffected();i++)
        {
            for(int j = 0 ;j < 8;j++)
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
        QMessageBox::critical(dqp,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqp,"错误",Error);
    }
}

DQPatient::DQPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DQPatient)
{
    ui->setupUi(this);
    setWindowTitle("Query Patient");
    connect(ui->btnQPatient,&QPushButton::clicked,[=](){
        if(ui->cbPatient->currentIndex() == 0)
        {
            //读取leQOffice编辑栏中的文字
            QString pmrno = ui->leQPatient->displayText();
            //调用函数查询
            querypmrno(pmrno,this);
            //使了编辑栏中的文字清零
            ui->leQPatient->setText("");
        }
        else if(ui->cbPatient->currentIndex() == 1)
        {
            QString ono = ui->leQPatient->displayText();
            queryono(ono,this);
            ui->leQPatient->setText("");
        }
        else if(ui->cbPatient->currentIndex() == 2)
        {
            QString odno = ui->leQPatient->displayText();
            querydwcno(odno,this);
            ui->leQPatient->setText("");
        }
        else if(ui->cbPatient->currentIndex() == 3)
        {
            QString pname = ui->leQPatient->displayText();
            querypname(pname,this);
            ui->leQPatient->setText("");
        }
    });
    connect(ui->btnQClose,&QPushButton::clicked,[=](){
        DQPatient::close();
    });
}

DQPatient::~DQPatient()
{
    delete ui;
}


