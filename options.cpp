#include "options.h"
#include "ui_options.h"
#include "filiers.h"
#include "etudiant.h"
#include "prof.h"
#include "emplois.h"

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
void options::on_prof_clicked()
{
    prof window;
    window.exec();
}


void options::on_note_clicked()
{

    emplois window;
    window.exec();
}

