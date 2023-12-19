#ifndef EMPLOIS_H
#define EMPLOIS_H

#include <QDialog>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class emplois;
}

class emplois : public QDialog
{
    Q_OBJECT

public:
    explicit emplois(QWidget *parent = nullptr);
    ~emplois();

private slots:
    void on_pushButton_clicked();

    void on_Cyc1_clicked();

    void on_Cyc2_clicked();

    void on_Cyc3_clicked();

    void on_LicEmp_clicked();

    void on_MSTEmp_clicked();

private:
    Ui::emplois *ui;
};

#endif // EMPLOIS_H
