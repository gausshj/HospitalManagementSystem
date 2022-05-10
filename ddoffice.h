#ifndef DDOFFICE_H
#define DDOFFICE_H

#include <QDialog>

namespace Ui {
class DDOffice;
}

class DDOffice : public QDialog
{
    Q_OBJECT

public:
    explicit DDOffice(QWidget *parent = nullptr);
    ~DDOffice();

private:
    Ui::DDOffice *ui;
};

#endif // DDOFFICE_H
