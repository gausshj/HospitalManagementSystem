#ifndef DQPATIENT_H
#define DQPATIENT_H

#include <QDialog>

namespace Ui {
class DQPatient;
}

class DQPatient : public QDialog
{
    Q_OBJECT

public:
    explicit DQPatient(QWidget *parent = nullptr);
    ~DQPatient();

private:
    Ui::DQPatient *ui;
};

#endif // DQPATIENT_H
