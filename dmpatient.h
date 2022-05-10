#ifndef DMPATIENT_H
#define DMPATIENT_H

#include <QDialog>

namespace Ui {
class DMPatient;
}

class DMPatient : public QDialog
{
    Q_OBJECT

public:
    explicit DMPatient(QWidget *parent = nullptr);
    ~DMPatient();

private:
    Ui::DMPatient *ui;
};

#endif // DMPATIENT_H
