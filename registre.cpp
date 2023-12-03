#include "registre.h"
#include "ui_registre.h"
#include "db.h"
#include <QMessageBox>


registre::registre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registre)
{
    ui->setupUi(this);
}

registre::~registre()
{
    delete ui;
}

void registre::on_reg_button_clicked()
{
    //registre (pas encore)
    QString username , password,nom,prenom,cne,cin,date ;
    username = ui->lineEdit_7username->text();
    password = ui->lineEdit_8password->text();
    nom = ui->lineEdit_1nom->text();
    prenom  = ui->lineEdit_2prenom->text();
    cne = ui->lineEdit_3cne->text();
    cin = ui->lineEdit_4cin->text();
    date = ui->dateEdit-> text();



    //
    /*
     * //hada nsah
    if(username.isEmpty() || password.isEmpty() || cne.isEmpty() || cin.isEmpty() || date.isEmpty() || nom.isEmpty() || prenom.isEmpty()){
        qDebug() << "empty !!";
        QMessageBox::critical(this,tr("Attention "),tr("des informations non cmplet ! ")) ;
    }
    else{
        DB conn ;
        if(!conn.connect_db())
            qDebug() << "Failed to open Database " ;
        conn.connect_db();
        QSqlQuery qry ;
        qry.prepare("insert into Login (username , password) values ('"+username+"','"+password+"' ) "); // katpreparer commande sql
        if(qry.exec())
        {
            QMessageBox::information(this,tr("Save"),tr("Saved")) ;
            conn.Deconnect_db();
        }
        else
            QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());

        //===========================
        conn.connect_db();
        QSqlQuery qr ;
        qr.prepare("insert into etudiant (nom,prenom,cne,cin,date) values ('"+nom+"','"+prenom+"','"+cne+"','"+cin+"','"+date+"') "); // katpreparer commande sql
        qDebug()<< qr.lastQuery() ;
        if(qr.exec())
        {
            conn.Deconnect_db();
        }
        else
            QMessageBox::critical(this,tr("Erreur"),qr.lastError().text());

        //fin registre
    }
*/
    DB conn ; // objet de connexion avec database
    conn.connect_db();
    QSqlQuery qr ;
    //etudiant
    qr.prepare("insert into etudiant (nom,prenom,cne,cin,date_ne) values ('"+nom+"','"+prenom+"','"+cne+"','"+cin+"','"+date+"') "); // katpreparer commande sql
    qDebug()<< qr.lastQuery() ;
    if(qr.exec() &&  !cne.isEmpty() && !cin.isEmpty() && !date.isEmpty() && !nom.isEmpty() && !prenom.isEmpty()&& !username.isEmpty() && !password.isEmpty())
    {
        //login
        QSqlQuery qry ;
        qry.prepare("insert into Login (username , password) values ('"+username+"','"+password+"' ) "); // katpreparer commande sql
        if(qry.exec())
        {
            QMessageBox::information(this,tr("Save"),tr("Saved")) ;
            conn.Deconnect_db();
        }
        else
            QMessageBox::critical(this,tr("Erreur"),qry.lastError().text());
    }
    else{
        qDebug() << qr.lastError().text();
        ui->lab->setText("erreur : "+qr.lastError().text());
    }

    if(username.isEmpty() || password.isEmpty() || cne.isEmpty() || cin.isEmpty() || date.isEmpty() || nom.isEmpty() || prenom.isEmpty()){
        qDebug() << "empty !!";
        QMessageBox::critical(this,tr("Attention "),tr("des informations non cmplet ! ")) ;
    }





        //===========================

}

