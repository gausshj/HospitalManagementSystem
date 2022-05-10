#ifndef DIWARD_H
#define DIWARD_H

#include <QDialog>

namespace Ui {
class DIWard;
}

class DIWard : public QDialog
{
    Q_OBJECT

public:
    explicit DIWard(QWidget *parent = nullptr);
    ~DIWard();

private:
    Ui::DIWard *ui;
};

#endif // DIWARD_H
