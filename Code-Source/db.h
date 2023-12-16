#ifndef DB_H
#define DB_H
#include<QtSql>
class DB
{
public:
    QSqlDatabase mydb ;
    DB();
    bool connect_db();
    bool Deconnect_db();
    ~DB();

};

#endif // DB_H
