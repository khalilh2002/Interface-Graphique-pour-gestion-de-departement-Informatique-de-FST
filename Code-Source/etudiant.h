#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QtCore>
#include<QtSql>
#include"db.h"
#include <QDialog>


namespace Ui {
class etudiant;
}

class etudiant : public QDialog
{
    Q_OBJECT

public:
    explicit etudiant(QWidget *parent = nullptr);
    DB db;
    void refresh();
    ~etudiant();

private slots:
    void on_pushButton_registre_clicked();

    void on_pushButton_clicked();

    void on_pushButton_delete_clicked();

    void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::etudiant *ui;


};

#endif // ETUDIANT_H
