#include "emplois.h"
#include "ui_emplois.h"

emplois::emplois(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::emplois)
{
    ui->setupUi(this);
}

emplois::~emplois()
{
    delete ui;
}

void emplois::on_pushButton_clicked()
{

}


void emplois::on_Cyc1_clicked()
{
    QUrl websiteUrl("https://drive.google.com/file/d/12JMV8215eNGQauJWPzigZmhLCSpiJA5r/view");
    QDesktopServices::openUrl(websiteUrl);
}


void emplois::on_Cyc2_clicked()
{
    QUrl websiteUrl("https://drive.google.com/file/d/1FOwFcVJPhGcjvD_SHxlMyqfW8obz-wYG/view?usp=drive_link");
    QDesktopServices::openUrl(websiteUrl);
}


void emplois::on_Cyc3_clicked()
{
    QUrl websiteUrl("https://drive.google.com/file/d/1ZFqOpKrJwPWgfxsgi4fYOYNgFKQpZgrc/view");
    QDesktopServices::openUrl(websiteUrl);
}


void emplois::on_LicEmp_clicked()
{
    QUrl websiteUrl("https://drive.google.com/file/d/1P_GmwoSUudAqhM5xHeSNxKofouuel3Ag/view");
    QDesktopServices::openUrl(websiteUrl);
}


void emplois::on_MSTEmp_clicked()
{
    QUrl websiteUrl("https://drive.google.com/file/d/1vpItfCizLjBGAuY0ZMasgqcFc7s_QlQV/view");
    QDesktopServices::openUrl(websiteUrl);
}

