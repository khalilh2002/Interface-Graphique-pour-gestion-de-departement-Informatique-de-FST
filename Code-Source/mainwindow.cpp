#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "options.h"
#include "about.h"


#include<iostream>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DB conn ;

    if(conn.connect_db())
        ui->label_info->setText("Connecting...");
    else
        ui->label_info->setText("Database disconnected");

    this->setFixedSize(380,300); //fixer la taille de page

}

MainWindow::~MainWindow()
{
    this->db.Deconnect_db();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    DB conn ;
    conn.connect_db();

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QSqlQuery query;

    QString cmd="Select * from login where username = '"+username+"' and password='"+password+"'" ;

    if(query.exec(cmd)){
        bool find = false;
        while(query.next()){
            find = true;
        }
        if(find){

            query.finish();
            if(query.isActive())
                qDebug()<<"stil avtive";
            ui->label_info->setText("its correct");
            options a ;
            a.exec();
            conn.Deconnect_db();

        }else{
            ui->label_info->setText("incorrect ");
        }
    }




}


void MainWindow::on_pushButton_2_clicked()
{
    about b ;
    b.exec() ;
}

