#include "etudiant.h"
#include "ui_etudiant.h"
#include "registre.h"


#include <QTableWidget>
#include <QTableWidgetItem>
#include <QWidget>
#include <QMessageBox>



etudiant::etudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::etudiant)
{
    ui->setupUi(this);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    refresh();




}

void etudiant::refresh(){
    DB conn;
    conn.connect_db();
    //requet de execution
    QSqlQuery query;

    //les command de sql
    QString cmd_selct="SELECT * FROM etudiant";
    QString cmd_count="SELECT Count(*)from etudiant";

    if(query.exec(cmd_count) and query.first()){
        int row_total=query.value(0).toInt();
        qDebug()<<row_total;
        ui->tableWidget->setRowCount(row_total); // set number of rows in table
    }else{
        qDebug() << "Error executing query:" << query.lastError().text();

    }
    query.clear();
    query.finish();
    QSqlQuery qry ;
    if(qry.exec(cmd_selct)){
        int row=0;
        while(qry.next()){
            for(int col=0 ; col < 5;col++){
                qDebug()<<qry.value(col+1).toString();
                QTableWidgetItem* item = new QTableWidgetItem(qry.value(col+1).toString());
                ui->tableWidget->setItem(row, col, item);
            }
            row++;
        }
        query.clear();
        query.finish();

    }
}

etudiant::~etudiant()
{
    //mydb.close();
    delete ui;
}

/*
void etudiant::on_pushButton_registre_clicked()
{

    int row=ui->tableWidget->rowCount();
    qDebug()<<" the last row is "<<row;
    int col_total=ui->tableWidget->columnCount();
    QSqlQuery qry;
    QString cmd_insert="INSERT INTO etudiant (nom, prenom,cne,cin,date_ne)\
        VALUES ('%1', '%2','%3','%4','%5');";

    QTableWidgetItem *item ;

    for(int col = 0 ; col <col_total ;col++ ){
        item = ui->tableWidget->item(row-1,col);
        if(item==NULL){
            qDebug()<<"error "<<col;
        }

        cmd_insert.replace("%"+QString::number(col+1),item->text());
    }

    qDebug()<<cmd_insert;
    if (!qry.exec(cmd_insert)) {
        qDebug() << "Error executing query:" << qry.lastError().text();
    } else {
        qDebug() << "Data inserted successfully!";
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    }

    //delete item;

}
*/

void etudiant::on_pushButton_clicked() //refresh button
{
    refresh();

}


void etudiant::on_pushButton_delete_clicked()
{
    DB conn;
    conn.connect_db();
    ui->tableWidget->selectedItems();

    if(!ui->tableWidget->selectedItems().empty()){
    QString cne_delete ;
    cne_delete = ui->tableWidget->selectedItems().at(2)->text() ;
    qDebug()<<cne_delete;

    QString cmd_delete=" DELETE FROM etudiant WHERE cne = 'var_delete';";
    cmd_delete.replace("var_delete",cne_delete);
    QSqlQuery qry;
    if(qry.exec(cmd_delete)){
        qDebug()<<"delete susccefully ";
    }else{
        qDebug()<<"delete worng  "+qry.lastError().text();

    }
    refresh();
    }
    else
        qDebug()<< "empty !! ";

}


void etudiant::on_pushButton_registre_clicked()
{
    registre r ;
    r.exec();
}


void etudiant::on_tableWidget_cellActivated(int row, int column)
{

}

