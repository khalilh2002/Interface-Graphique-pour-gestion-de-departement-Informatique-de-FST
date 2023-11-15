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

#include<cstring>
/**/

int calcul(FILE *f){
    int nb=0;
    char *tmp;
    while(feof(f)==0){
        fscanf(f,"%s %s %s %s %s",tmp,tmp,tmp,tmp,tmp);
        nb++;
    }
    rewind(f);
    //qDebug() << nb<<"\n";
    return nb--;
}

etudiant::etudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::etudiant)
{
    ui->setupUi(this);

    /*test*/
    FILE *etu;
    int taille_fichier=2;

    etu=fopen("C:\\Users\\khali\\Desktop\\classroom\\untitled1\\txt\\etudiant.txt","r+");//source des donner des etudiant
    if(etu==NULL){
        QMessageBox :: warning(this,"title","this file is not exsit etudiant");
    }

    taille_fichier=calcul(etu); //la taille des fichier

    ui->tableWidget->setColumnCount(5);//"CNE"<<"Nom"<<"Prenom"<<"CIN"<<"Date de naison"
    ui->tableWidget->setRowCount(taille_fichier);

    QStringList list_header; //la paarite haut de tableau
    list_header<<"CNE"<<"Nom"<<"Prenom"<<"CIN"<<"Date de nee";//list
    ui->tableWidget->setHorizontalHeaderLabels(list_header);


    /*table pour stcker les donnees des etudiant*/

    char **data = new char*[5];
        for (int i = 0; i < 5; ++i) {
        data[i] = new char[20];
    }
    /*
     * data[0]=CNE
     * date[1]=NOM
     * date[2]=Prenom
     * date[3]=CIN
     * date[4]=Date
    */
    for (int row = 0; row < taille_fichier-1; ++row) { //-1 car la debut de taleau est '0'
        fscanf(etu,"%s %s %s %s %s",data[0],data[1],data[2],data[3],data[4]);//scaner line par line
        for (int col = 0; col < 5; ++col) {

            QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(QString(data[col])));
            ui->tableWidget->setItem(row,col,item);
            qDebug() << data[0]<<" ";

        }
        std::cout<<std::endl;

    }
    fclose(etu);
}




etudiant::~etudiant()
{
    delete ui;
}


