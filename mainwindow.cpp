#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "options.h"
#include<iostream>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    this->db.Deconnect_db();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

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

        }else{
            ui->label_info->setText("incorrect ");
        }
    }




}

