#ifndef DDDOCTOR_H
#define DDDOCTOR_H

#include <QDialog>

namespace Ui {
class DDDoctor;
}

class DDDoctor : public QDialog
{
    Q_OBJECT

public:
    explicit DDDoctor(QWidget *parent = nullptr);
    ~DDDoctor();

private:
    Ui::DDDoctor *ui;
};

#endif // DDDOCTOR_H
