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

#include <cstring>
#include <QFileDialog>
/**/




etudiant::etudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::etudiant)
{
    ui->setupUi(this);
    QFile CSVFile(QCoreApplication::applicationDirPath() + "/csvetud.csv");
    if (CSVFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&CSVFile);
        int row = 0;
        while (!stream.atEnd())
        {
            QString lineData = stream.readLine();
            QStringList columnData = lineData.split(';');
            for (int col = 0; col < columnData.size(); ++col)
            {
                QTableWidgetItem* item = new QTableWidgetItem(columnData[col]);
                ui->tableWidget->setItem(row, col, item);
            }
            ++row;
        }
        CSVFile.close();
    }
    else
    {
        // Handle the case when the file cannot be opened
        qDebug() << "Failed to open the CSV file.";
    }


}


etudiant::~etudiant()
{
    delete ui;
}
/*continue ici*/


void etudiant::on_pushButton_registre_clicked()
{
    // Step 1: Add a new row to the QTableWidget
    int newRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(newRow);

    // Step 2: Obtain data for the new row (you can modify this part)
    QString name = "New Name";
    QString age = "20";
    QString grade = "A";

    // Step 3: Insert the data into the new row in the QTableWidget
    QTableWidgetItem* nameItem = new QTableWidgetItem(name);
    QTableWidgetItem* ageItem = new QTableWidgetItem(age);
    QTableWidgetItem* gradeItem = new QTableWidgetItem(grade);

    ui->tableWidget->setItem(newRow, 0, nameItem);  // Assuming name is in column 0
    ui->tableWidget->setItem(newRow, 1, ageItem);   // Assuming age is in column 1
    ui->tableWidget->setItem(newRow, 2, gradeItem); // Assuming grade is in column 2

    // Step 4: Open the CSV file in append mode and write the data for the new row
    QFile CSVFile(QCoreApplication::applicationDirPath() + "/csvetud.csv");
    if (CSVFile.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&CSVFile);

        // Write data for the new row to the CSV file
        for (int c = 0; c < ui->tableWidget->columnCount(); ++c)
        {
            QTableWidgetItem* cellItem = ui->tableWidget->item(newRow, c);
            if (cellItem)
            {
                stream << cellItem->text();
                if (c < ui->tableWidget->columnCount() - 1)
                    stream << ";"; // Add the column delimiter
            }
        }

        stream << "\n"; // Add a newline after each row

        CSVFile.close();
    }
    else
    {
        qDebug() << "Failed to open the CSV file for appending.";
    }
}







void etudiant::on_tableWidget_cellChanged(int row, int column)
{
    // Obtenez le texte de la cellule modifiée
    QTableWidgetItem *item = ui->tableWidget->item(row, column);
    QString newText = item->text();

    // Ouvrez le fichier en écriture
    QFile CSVFile(QCoreApplication::applicationDirPath() + "/csvetud.csv");
    if (CSVFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&CSVFile);

        // Parcourez toutes les lignes et colonnes pour écrire les données dans le fichier
        for (int r = 0; r < ui->tableWidget->rowCount(); ++r)
        {
            for (int c = 0; c < ui->tableWidget->columnCount(); ++c)
            {
                QTableWidgetItem *cellItem = ui->tableWidget->item(r, c);
                if (cellItem)
                    stream << cellItem->text();
                if (c < ui->tableWidget->columnCount() - 1)
                    stream << ";" ; // Ajoutez le délimiteur de colonne
            }
            stream << "\n" ; // Ajoutez un saut de ligne après chaque ligne
        }

        CSVFile.close();
    }
    else
    {
        // Gérez le cas où le fichier ne peut pas être ouvert en écriture
        qDebug() << "Failed to open the CSV file for writing.";
    }
}
