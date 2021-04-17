/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 18.04.2021
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString res = "";

    Dictionary<int, QString> *dict = new Dictionary<int, QString>();
    dict->add(1,"Burak");
    dict->add(2,"Hamdi");
    dict->add(3,"Tufan");
    dict->add(4,"The");
    dict->add(5,"Code");
    dict->add(6,"Program");

    res += "Added some values to dictionary with keys...\n";
    res += "Dictionary Size : " + QString::number( dict->getSize() ) + " \n";

    res += dict->getAllValues();

    res +=  QStringLiteral("Value with key 3 : %1. \n").arg( dict->getWithkey(3) ) ;
    res +=  QStringLiteral("Value with key 5 : %1. \n\n").arg( dict->getWithkey(5) ) ;

    dict->removeFromKey(1);

    res += "Removed data on Key 1...\n";
    res += "Dictionary Size : " + QString::number( dict->getSize() ) + " \n";
    res +=  QStringLiteral("Value with key 2 : %1. \n").arg( dict->getWithkey(2) ) ;

    res += dict->getAllValues();

    res += "Key-Value pair at key 4 -> " + dict->getPairAtKey(4);

    ui->plainTextEdit->setPlainText(res);
}

MainWindow::~MainWindow()
{
    delete ui;
}

