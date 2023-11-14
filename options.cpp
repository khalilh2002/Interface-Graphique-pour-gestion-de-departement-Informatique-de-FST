#include "options.h"
#include "ui_options.h"
#include "filiers.h"
#include "etudiant.h"

options::options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::options)
{
    ui->setupUi(this);
}

options::~options()
{
    delete ui;
}

void options::on_filiers_clicked()
{
    filiers windows;

    windows.exec();
}


void options::on_etudiant_clicked()
{
    etudiant window;
    window.exec();
}

