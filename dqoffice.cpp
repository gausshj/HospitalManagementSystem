#include "dqoffice.h"
#include "ui_dqoffice.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidget>

void queryono(QString ono,DQOffice *dqo)
{
    QSqlQuery query;
    QString str = QString("select * from Office where ono = '%1'").arg(ono);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Office");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(5);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"科室编号"<<"科室名"<<"科地址"<<"联系电话"<<"科室主任编号");
        qtw->setItem(0,0,new QTableWidgetItem(ono));
        for(int i = 1;i < 5;i++)
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
        QMessageBox::critical(dqo,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqo,"错误",Error);
    }
}
void queryoname(QString oname,DQOffice *dqo)
{
    QSqlQuery query;
    QString str = QString("select * from Office where oname = '%1'").arg(oname);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Office");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(5);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"科室编号"<<"科室名"<<"科地址"<<"联系电话"<<"科室主任编号");
        for(int i =0;i < query.numRowsAffected();i++)
        {
            for(int j=0 ;j < 5;j++)
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
        QMessageBox::critical(dqo,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqo,"错误",Error);
    }
}
void queryodno(QString odno,DQOffice *dqd)
{
    QSqlQuery query;
    QString str = QString("select * from Office where odno = '%1'").arg(odno);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Office");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(5);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"科室编号"<<"科室名"<<"科地址"<<"联系电话"<<"科室主任编号");
        for(int i = 0;i < query.numRowsAffected();i++)
        {
            for(int j = 0 ;j < 5;j++)
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

DQOffice::DQOffice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DQOffice)
{
    ui->setupUi(this);
    setWindowTitle("Query Office");
    connect(ui->btnQOffice,&QPushButton::clicked,[=](){
        if(ui->cbOffice->currentIndex() == 0)
        {
            //读取leQOffice编辑栏中的文字
            QString ono = ui->leQOffice->displayText();
            //调用函数查询
            queryono(ono,this);
            //使了编辑栏中的文字清零
            ui->leQOffice->setText("");
        }
        else if(ui->cbOffice->currentIndex() == 1)
        {
            QString oname = ui->leQOffice->displayText();
            queryoname(oname,this);
            ui->leQOffice->setText("");
        }
        else if(ui->cbOffice->currentIndex() == 2)
        {
            QString odno = ui->leQOffice->displayText();
            queryodno(odno,this);
            ui->leQOffice->setText("");
        }
    });
    connect(ui->btnQClose,&QPushButton::clicked,[=](){
        DQOffice::close();
    });
}

DQOffice::~DQOffice()
{
    delete ui;
}


