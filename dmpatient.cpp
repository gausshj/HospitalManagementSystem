#include "dmpatient.h"
#include "ui_dmpatient.h"

DMPatient::DMPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DMPatient)
{
    ui->setupUi(this);
}

DMPatient::~DMPatient()
{
    delete ui;
}
