#ifndef DIOFFICE_H
#define DIOFFICE_H

#include <QDialog>

namespace Ui {
class DIOffice;
}

class DIOffice : public QDialog
{
    Q_OBJECT

public:
    explicit DIOffice(QWidget *parent = nullptr);
    ~DIOffice();

private:
    Ui::DIOffice *ui;
};

#endif // DIOFFICE_H
