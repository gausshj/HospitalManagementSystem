#include "dmward.h"
#include "ui_dmward.h"

DMWard::DMWard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DMWard)
{
    ui->setupUi(this);
}

DMWard::~DMWard()
{
    delete ui;
}
