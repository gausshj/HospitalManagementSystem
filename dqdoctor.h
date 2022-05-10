#ifndef DQDOCTOR_H
#define DQDOCTOR_H

#include <QDialog>

namespace Ui {
class DQDoctor;
}

class DQDoctor : public QDialog
{
    Q_OBJECT

public:
    explicit DQDoctor(QWidget *parent = nullptr);
    ~DQDoctor();

private:
    Ui::DQDoctor *ui;
};

#endif // DQDOCTOR_H
