#include "prof.h"
#include "ui_prof.h"
#include "regprof.h"

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QWidget>
#include <QMessageBox>






prof::prof(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prof)
{
    ui->setupUi(this);
    // to stop user of editing the info
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //afficher
    refresh();


}


prof::~prof()
{
    delete ui;
}






void prof::on_pushButton_refrech_clicked()
{
    refresh();
}


void prof::refresh(){
    //requet de execution
    DB conn ;
    conn.connect_db();
    QSqlQuery query;

    //les command de sql
    QString cmd_selct="SELECT * FROM prof";
    QString cmd_count="SELECT Count(*)from prof";

    if(query.exec(cmd_count) and query.first()){
        //les resulat de cont()
        int row_total=query.value(0).toInt();
        qDebug()<<row_total;

        //set les nombres des lignes
        ui->tableWidget->setRowCount(row_total); // set number of rows in table
    }else{
        qDebug() << "Error executing query:" << query.lastError().text();

    }
    query.clear();
    query.finish();

    if(query.exec(cmd_selct)){
        //afficher les tableaus sur Tableau
        int row=0;
        // lire lie par line
        while(query.next()){
            //lire colone par colone
            for(int col=0 ; col < 5;col++){
                //query.vallue(col+1) pour afficher 'nom'(1) 'prenom'(2) ...
                qDebug()<<query.value(col+1).toString();
                //set item pour le tableau
                QTableWidgetItem* item = new QTableWidgetItem(query.value(col+1).toString());
                //set chaque item
                ui->tableWidget->setItem(row, col, item);
            }
            row++;
        }
        query.clear();
        query.finish();

    }
}


void prof::on_pushButton_delete_clicked()
{
    //deteerminer la ligne qui l utilisateur selectioner
    DB conn ;
    conn.connect_db();
    //si lustilisateur ne selectioner rien
    if(!ui->tableWidget->selectedItems().empty()){
        QString cne_delete = ui->tableWidget->selectedItems().at(2)->text();
        qDebug()<<cne_delete;

        QString cmd_delete=" DELETE FROM prof WHERE CIN = 'var_delete';";
        cmd_delete.replace("var_delete",cne_delete);
        QSqlQuery qry;
        if(qry.exec(cmd_delete)){
            qDebug()<<"delete susccefully ";
        }else{
            qDebug()<<"delete worng  "+qry.lastError().text();

        }
        refresh();
    }

}


void prof::on_pushButton_registre_clicked()
{
    regprof pr ;
    pr.exec();
}

