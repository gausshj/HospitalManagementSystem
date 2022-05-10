#ifndef DIPATIENT_H
#define DIPATIENT_H

#include <QDialog>

namespace Ui {
class DIPatient;
}

class DIPatient : public QDialog
{
    Q_OBJECT

public:
    explicit DIPatient(QWidget *parent = nullptr);
    ~DIPatient();

private:
    Ui::DIPatient *ui;
};

#endif // DIPATIENT_H
