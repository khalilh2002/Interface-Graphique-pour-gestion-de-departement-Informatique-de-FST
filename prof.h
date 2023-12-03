#ifndef prof_H
#define prof_H
#include <QtCore>
#include "db.h"
#include <QtSql>
#include <QDialog>

namespace Ui {
class prof;
}

class prof : public QDialog
{
    Q_OBJECT

public:
    explicit prof(QWidget *parent = nullptr);
    ~prof();

private slots:


    void on_pushButton_registre_clicked();

    void on_pushButton_refrech_clicked();

    void refresh();

    void on_pushButton_delete_clicked();

private:
    Ui::prof *ui;

};

#endif // prof_H
