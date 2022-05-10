#ifndef DDPATIENT_H
#define DDPATIENT_H

#include <QDialog>

namespace Ui {
class DDPatient;
}

class DDPatient : public QDialog
{
    Q_OBJECT

public:
    explicit DDPatient(QWidget *parent = nullptr);
    ~DDPatient();

private:
    Ui::DDPatient *ui;
};

#endif // DDPATIENT_H
