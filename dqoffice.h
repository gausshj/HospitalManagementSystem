#ifndef DQOFFICE_H
#define DQOFFICE_H

#include <QDialog>

namespace Ui {
class DQOffice;
}

class DQOffice : public QDialog
{
    Q_OBJECT

public:
    explicit DQOffice(QWidget *parent = nullptr);
    ~DQOffice();

private:
    Ui::DQOffice *ui;
};

#endif // DQOFFICE_H
