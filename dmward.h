#ifndef DMWARD_H
#define DMWARD_H

#include <QDialog>

namespace Ui {
class DMWard;
}

class DMWard : public QDialog
{
    Q_OBJECT

public:
    explicit DMWard(QWidget *parent = nullptr);
    ~DMWard();

private:
    Ui::DMWard *ui;
};

#endif // DMWARD_H
