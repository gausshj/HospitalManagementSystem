#ifndef DMDOCTOR_H
#define DMDOCTOR_H

#include <QDialog>

namespace Ui {
class DMDoctor;
}

class DMDoctor : public QDialog
{
    Q_OBJECT

public:
    explicit DMDoctor(QWidget *parent = nullptr);
    ~DMDoctor();

private:
    Ui::DMDoctor *ui;
};

#endif // DMDOCTOR_H
