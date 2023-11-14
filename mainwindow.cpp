#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "options.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    using namespace std;
    bool found=false; //katchof wach password o username exsit
    char name[50] , password[50];
    FILE *log;
    QString name_given=ui->lineEdit_username->text();
    QString  password_given=ui->lineEdit_password->text();
    /*had khaso i tmodifia bnsba lokola pc*/
    log = fopen("C:\\Users\\khali\\Desktop\\classroom\\untitled1\\txt\\login.txt","r");

    if(log==NULL){
        QMessageBox::warning(this,"login info","file is not here");

    }
    rewind(log); /*ktrj3 lwl*/
    /*kt9lb 3la l user*/
    while(feof(log)==0){
        fscanf(log,"%s %s",name,password);

        if(name_given==name && password_given==password){ /*camparer betwen qstring et char* */
            found=true;
        }
    }
    if(found==true){
        QMessageBox::information(this,"login info","the login is correct");
        options new_window;
        new_window.setWindowFlag(Qt::Window);
        //new_window.show();
        close();
        new_window.exec();


    }else{

      QMessageBox::warning(this,"login info","the login is worong");
    }
    fclose(log);


}

