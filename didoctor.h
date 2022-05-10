#ifndef DIDOCTOR_H
#define DIDOCTOR_H

#include <QDialog>

namespace Ui {
class DIDoctor;
}

class DIDoctor : public QDialog
{
    Q_OBJECT

public:
    explicit DIDoctor(QWidget *parent = nullptr);
    QStringList setleEText(QString dwcno);
    QStringList readleEText();
    void setconnect();
    ~DIDoctor();

private:
    Ui::DIDoctor *ui;
};

#endif // DIDOCTOR_H
