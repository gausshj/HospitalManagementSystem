#ifndef DDWARD_H
#define DDWARD_H

#include <QDialog>

namespace Ui {
class DDWard;
}

class DDWard : public QDialog
{
    Q_OBJECT

public:
    explicit DDWard(QWidget *parent = nullptr);
    ~DDWard();

private:
    Ui::DDWard *ui;
};

#endif // DDWARD_H
