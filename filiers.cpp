#include "filiers.h"
#include "ui_filiers.h"


filiers::filiers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filiers)
{
    ui->setupUi(this);
}

filiers::~filiers()
{
    delete ui;
}




