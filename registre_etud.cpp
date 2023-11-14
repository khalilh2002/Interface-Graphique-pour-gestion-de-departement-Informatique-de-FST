#include "registre_etud.h"
#include "ui_registre_etud.h"

registre_etud::registre_etud(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registre_etud)
{
    ui->setupUi(this);
}

registre_etud::~registre_etud()
{
    delete ui;
}
