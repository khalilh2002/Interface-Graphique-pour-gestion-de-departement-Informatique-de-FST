#ifndef REGISTRE_ETUD_H
#define REGISTRE_ETUD_H

#include <QDialog>

namespace Ui {
class registre_etud;
}

class registre_etud : public QDialog
{
    Q_OBJECT

public:
    explicit registre_etud(QWidget *parent = nullptr);
    ~registre_etud();

private:
    Ui::registre_etud *ui;
};

#endif // REGISTRE_ETUD_H
