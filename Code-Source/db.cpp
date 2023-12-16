#include "db.h"

DB::DB()
{
    connect_db();
}






bool DB::connect_db(){
    mydb = QSqlDatabase::addDatabase("QSQLITE");



    // Get the directory where the executable is located
    QString appDir = QCoreApplication::applicationDirPath();

    // Set the database file name relative to the executable location
    //mydb.setDatabaseName(appDir + QDir::separator() + "Data_base.db");


    mydb.setDatabaseName("C:\\Users\\dell\\Desktop\\Data_base.db");






    if(!mydb.open()){
        qDebug()<<"error is not connected "<<mydb.lastError().text();
        return false;
    }else{
        qDebug()<<"connceted succefully";
        return true;
    }
}

bool DB::Deconnect_db(){
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
    if(mydb.open()){
        return false;
    }else{
        return true;
    }
}

DB::~DB(){
    this->Deconnect_db();
}
