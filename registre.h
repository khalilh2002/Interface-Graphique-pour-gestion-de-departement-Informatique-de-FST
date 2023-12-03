#ifndef REGISTRE_H
#define REGISTRE_H

#include <QDialog>

namespace Ui {
class registre;
}

class registre : public QDialog
{
    Q_OBJECT

public:
    explicit registre(QWidget *parent = nullptr);
    ~registre();

private slots:
    void on_reg_button_clicked();

private:
    Ui::registre *ui;
};

#endif // REGISTRE_H
