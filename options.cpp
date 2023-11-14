#include "options.h"
#include "ui_options.h"
#include "filiers.h"

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
    close();
    windows.exec();
}

