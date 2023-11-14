#include "etudiant.h"
#include "ui_etudiant.h"

/*test new from chatgpt*/
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

#include <cstdio>

#include<iostream>
/**/

int calcul(FILE *f){
    int nb=0;
    while(feof(f)==0){
        nb++;
    }
    return nb;
}

etudiant::etudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::etudiant)
{
    ui->setupUi(this);

    /*test*/
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(2);

    QStringList list_header;
    list_header<<"CNE"<<"Nom"<<"Prenom"<<"CIN"<<"Date de naison";
    ui->tableWidget->setHorizontalHeaderLabels(list_header);

    FILE *etu;
    etu=fopen("C:\\Users\\khali\\Desktop\\classroom\\untitled1\\txt\\etudiant.txt","r+");
    if(etu==NULL){
        QMessageBox :: warning(this,"title","this file is not exsit etudiant");
    }

    char cne[20],nom[20],prenom[20],date[20],cin[20];

    /*table*/

    char **data = new char*[5];
        for (int i = 0; i < 5; ++i) {
        data[i] = new char[20];
    }

    for (int row = 0; row < 2; ++row) {
        fscanf(etu,"%s %s %s %s %s",data[1],nom,prenom,date,cin);
        for (int col = 0; col < 5; ++col) {

            QTableWidgetItem *item = new QTableWidgetItem(QString("%1 ").arg(QString(cne))/*.arg(nom).arg(prenom).arg(date).arg(cin)*/);
            ui->tableWidget->setItem(row,col,item);
            qDebug() << nom<<"" <<prenom <<"" << date<<"\n";

        }

    }


}

etudiant::~etudiant()
{
    delete ui;
}
