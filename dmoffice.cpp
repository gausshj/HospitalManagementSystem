#include "dmoffice.h"
#include "ui_dmoffice.h"

DMOffice::DMOffice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DMOffice)
{
    ui->setupUi(this);
}

DMOffice::~DMOffice()
{
    delete ui;
}
