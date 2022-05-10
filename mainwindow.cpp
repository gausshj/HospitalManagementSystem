#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dddoctor.h"
#include "ddoffice.h"
#include "ddpatient.h"
#include "ddward.h"
#include "didoctor.h"
#include "dioffice.h"
#include "dipatient.h"
#include "diward.h"
#include "dmdoctor.h"
#include "dmoffice.h"
#include "dmpatient.h"
#include "dmward.h"
#include "dqdoctor.h"
#include "dqoffice.h"
#include "dqpatient.h"
#include "dqward.h"
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1000,600);
    setWindowTitle("简易医院信息管理系统");
    connect(ui->actionIDoctor,&QAction::triggered,[=](){
        DIDoctor *did = new DIDoctor(this);
        did->setModal(true);
        did->show();
        did->exec();
        delete did;
    });
    connect(ui->actionIOffice,&QAction::triggered,[=](){
        DIOffice *dio = new DIOffice(this);
        dio->setModal(true);
        dio->show();
        dio->exec();
        delete dio;
    });
    connect(ui->actionIPatient,&QAction::triggered,[=](){
        DIPatient *dip = new DIPatient(this);
        dip->setModal(true);
        dip->show();
        dip->exec();
        delete dip;
    });
    connect(ui->actionIWard,&QAction::triggered,[=](){
        DIWard *diw = new DIWard(this);
        diw->setModal(true);
        diw->show();
        diw->exec();
        delete diw;
    });
    connect(ui->actionDDoctor,&QAction::triggered,[=](){
        DDDoctor*ddd = new DDDoctor(this);
        ddd->setModal(true);
        ddd->show();
        ddd->exec();
        delete ddd;
    });
    connect(ui->actionDOffice,&QAction::triggered,[=](){
        DDOffice *ddo = new DDOffice(this);
        ddo->setModal(true);
        ddo->show();
        ddo->exec();
        delete ddo;
    });
    connect(ui->actionDPatient,&QAction::triggered,[=](){
        DDPatient *ddp =new DDPatient(this);
        ddp->setModal(true);
        ddp->show();
        ddp->exec();
        delete ddp;
    });
    connect(ui->actionDWard,&QAction::triggered,[=](){
        DDWard *ddw = new DDWard(this);
        ddw->setModal(true);
        ddw->show();
        ddw->exec();
        delete ddw;
    });
    connect(ui->actionMDoctor,&QAction::triggered,[=](){
        DMDoctor *dmd = new DMDoctor(this);
        dmd->setModal(true);
        dmd->show();
        dmd->exec();
        delete dmd;
    });
    connect(ui->actionMOffice,&QAction::triggered,[=](){
        DMOffice *dmo = new DMOffice(this);
        dmo->setModal(true);
        dmo->show();
        dmo->exec();
        delete dmo;
    });
    connect(ui->actionMPatient,&QAction::triggered,[=](){
        DMPatient *dmp = new DMPatient(this);
        dmp->setModal(true);
        dmp->show();
        dmp->exec();
        delete dmp;
    });
    connect(ui->actionMWard,&QAction::triggered,[=](){
        DMWard *dmw = new DMWard(this);
        dmw->setModal(true);
        dmw->show();
        dmw->exec();
        delete dmw;
    });
    connect(ui->actionQDoctor,&QAction::triggered,[=](){
        DQDoctor *dqd = new DQDoctor(this);
        dqd->setModal(true);
        dqd->show();
        dqd->exec();
        delete dqd;
    });
    connect(ui->actionQOffice,&QAction::triggered,[=](){
        DQOffice *dqo = new DQOffice(this);
        dqo->setModal(true);
        dqo->show();
        dqo->exec();
        delete dqo;
    });
    connect(ui->actionQPatient,&QAction::triggered,[=](){
        DQPatient *dqp = new DQPatient(this);
        dqp->setModal(true);
        dqp->show();
        dqp->exec();
        delete dqp;
    });
    connect(ui->actionQWard,&QAction::triggered,[=](){
        DQWard *dqw = new DQWard(this);
        dqw->setModal(true);
        dqw->show();
        dqw->exec();
        delete dqw;
    });
    connect(ui->actionAbout,&QAction::triggered,[=](){
        QDialog *qdg = new QDialog(this);
        qdg->resize(100,75);
        qdg->setFixedSize(100,75);
        qdg->move(700,400);
        qdg->setWindowTitle("About");
        QListWidget *about = new QListWidget(qdg);
        about->resize(100,75);
        about->setFixedSize(100,75);
        QStringList list;
        list<<"商品管理系统1.0"<<"版权保留";
        about->addItems(list);
        qdg->show();
        qdg->exec();
        delete qdg;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
