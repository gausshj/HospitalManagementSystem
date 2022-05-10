#ifndef DQWARD_H
#define DQWARD_H

#include <QDialog>

namespace Ui {
class DQWard;
}

class DQWard : public QDialog
{
    Q_OBJECT

public:
    explicit DQWard(QWidget *parent = nullptr);
    ~DQWard();

private:
    Ui::DQWard *ui;
};

#endif // DQWARD_H
