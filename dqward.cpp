#include "dqward.h"
#include "ui_dqward.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidget>

void querywno(QString wno,DQWard *dqw)
{
    QSqlQuery query;
    QString str = QString("select * from Ward where wno = '%1'").arg(wno);
    query.exec(str);
    if(query.next())
    {
        QDialog *qdg = new QDialog();
        qdg->setWindowTitle("Query in Ward");
        qdg->setModal(true);
        qdg->show();
        //插入QtableWidget
        QTableWidget *qtw = new QTableWidget(qdg);
        qtw->show();
        //设置列数
        qtw->setColumnCount(3);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"病房号"<<"科室编号"<<"病房住址");
        qtw->setItem(0,0,new QTableWidgetItem(wno));
        for(int i = 1;i < 3;i++)
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
        QMessageBox::critical(dqw,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqw,"错误",Error);
    }
}
void queryono(QString ono,DQWard *dqw)
{
    QSqlQuery query;
    QString str = QString("select * from Ward where ono = '%1'").arg(ono);
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
        qtw->setColumnCount(3);
        //设置行数
        qtw->setRowCount(query.numRowsAffected());
        //设置表头
        qtw->setHorizontalHeaderLabels(QStringList()<<"病房号"<<"科室编号"<<"病房住址");
        for(int i =0;i < query.numRowsAffected();i++)
        {
            for(int j=0 ;j < 3;j++)
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
        QMessageBox::critical(dqw,"错误","未查询到相关结果");
    }
    QString Error = query.lastError().text();
    if(Error.isEmpty())
    {
        QMessageBox::critical(dqw,"错误",Error);
    }
}

DQWard::DQWard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DQWard)
{
    ui->setupUi(this);
    setWindowTitle("Query Patient");
    connect(ui->btnQWard,&QPushButton::clicked,[=](){
        if(ui->cbWard->currentIndex() == 0)
        {
            //读取leQOffice编辑栏中的文字
            QString wno = ui->leQWard->displayText();
            //调用函数查询
            querywno(wno,this);
            //使了编辑栏中的文字清零
            ui->leQWard->setText("");
        }
        else if(ui->cbWard->currentIndex() == 1)
        {
            QString ono = ui->leQWard->displayText();
            queryono(ono,this);
            ui->leQWard->setText("");
        }
    });
    connect(ui->btnQClose,&QPushButton::clicked,[=](){
        DQWard::close();
    });
}

DQWard::~DQWard()
{
    delete ui;
}



