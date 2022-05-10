#ifndef DMOFFICE_H
#define DMOFFICE_H

#include <QDialog>

namespace Ui {
class DMOffice;
}

class DMOffice : public QDialog
{
    Q_OBJECT

public:
    explicit DMOffice(QWidget *parent = nullptr);
    ~DMOffice();

private:
    Ui::DMOffice *ui;
};

#endif // DMOFFICE_H
