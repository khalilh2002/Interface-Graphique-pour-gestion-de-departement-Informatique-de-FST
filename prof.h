#ifndef prof_H
#define prof_H
#include <QtCore>

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

    void on_tableWidget_cellChanged(int row, int column);

    void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::prof *ui;
    void loadCsvFileIntoTable(); // Declare the function

};

#endif // prof_H
