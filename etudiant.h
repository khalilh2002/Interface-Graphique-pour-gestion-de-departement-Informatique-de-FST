#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QDialog>

namespace Ui {
class etudiant;
}

class etudiant : public QDialog
{
    Q_OBJECT

public:
    explicit etudiant(QWidget *parent = nullptr);
    ~etudiant();

private slots:


    void on_pushButton_registre_clicked();

private:
    Ui::etudiant *ui;
};

#endif // ETUDIANT_H
