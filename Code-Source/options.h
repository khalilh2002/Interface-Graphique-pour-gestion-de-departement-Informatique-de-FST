#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

namespace Ui {
class options;
}

class options : public QDialog
{
    Q_OBJECT

public:
    explicit options(QWidget *parent = nullptr);
    ~options();

private slots:
    void on_filiers_clicked();

    void on_etudiant_clicked();

    void on_prof_clicked();

    void on_note_clicked();

private:
    Ui::options *ui;
};

#endif // OPTIONS_H
