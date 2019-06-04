#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlTableModel>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QStandardItem>

MainWindow::MainWindow(int lvl, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
       this->lvl = lvl;
       ui->setupUi(this);
       if(this->lvl == 0 || this->lvl == 2){
         ui->pushButton->setVisible(false);
       }
       QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "mydb");
       db.setHostName("localhost");
       db.setDatabaseName("demograf_db");
       db.setUserName("rootuser");
       db.setPassword("rootuser");
       bool ok = db.open();
       if(!ok){
           return;
       }
       QSqlQuery query(db);
       query.exec("SELECT DISTINCT state FROM demograf ORDER BY state");
       ui->listWidgetState->addItem("Все");
       while (query.next()) {
           QString name = query.value(0).toString();
           ui->listWidgetState->addItem(name);
       }
       query.exec("SELECT DISTINCT county FROM demograf ORDER BY county");
       ui->listWidgetCounty->addItem("Все");
       while (query.next()) {
           QString name = query.value(0).toString();
           ui->listWidgetCounty->addItem(name);
       }
       db.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidgetState_itemChanged(QListWidgetItem *item)
{
}

void MainWindow::on_listWidgetCounty_clicked(const QModelIndex &index)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "mydb");
    db.setHostName("localhost");
    db.setDatabaseName("demograf_db");
    db.setUserName("rootuser");
    db.setPassword("rootuser");
    bool ok = db.open();
    if(!ok){
        return;
    }
    QString listWidgetStateStr = ui->listWidgetState->item(ui->listWidgetState->currentRow ())->text();
    QString listWidgetCountyStr = ui->listWidgetCounty->item(ui->listWidgetCounty->currentRow ())->text();

    QStringList horizontalHeader;
    horizontalHeader.append("id");
    horizontalHeader.append("Штат");
    horizontalHeader.append("Гравство");
    horizontalHeader.append("Всего людей");
    horizontalHeader.append("Мужчин");
    horizontalHeader.append("Женшин");
    horizontalHeader.append("Черных");
    horizontalHeader.append("Белых");
    horizontalHeader.append("Азиатов");
    horizontalHeader.append("Коренных жителей");
    horizontalHeader.append("Пафицистов");
    horizontalHeader.append("Городских жителей");

    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item2;
    model->setHorizontalHeaderLabels(horizontalHeader);

    QString textSql = "SELECT * FROM demograf";
    if(listWidgetStateStr != "Все"){
        textSql += " WHERE state = '" + listWidgetStateStr + "'";
        if(listWidgetCountyStr != "Все"){
        textSql += "  and county = '" + listWidgetCountyStr + "'";
        }
    }
    QSqlQuery query(db);
    query.exec(textSql);
    int count = 0;
    while (query.next()) {
        for(int g = 0; g < 17; g++){
            QString name = query.value(g).toString();
            item2 = new QStandardItem(name);
            model->setItem(count, g, item2);
        }
        count++;
    }
    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    if(this->lvl){
         ui->tableView->editTriggers();
    }
    db.close();
}

void MainWindow::on_listWidgetState_clicked(const QModelIndex &index)
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "mydb");
    db.setHostName("localhost");
    db.setDatabaseName("demograf_db");
    db.setUserName("rootuser");
    db.setPassword("rootuser");
    bool ok = db.open();
    if(!ok){
        return;
    }
    QString listWidgetStateStr = ui->listWidgetState->item(ui->listWidgetState->currentRow ())->text();
    QString textSql = "SELECT DISTINCT county FROM demograf";
    if(listWidgetStateStr != "Все"){
        textSql += " WHERE state = '" + listWidgetStateStr + "' ORDER BY county";
    }
    ui->listWidgetCounty->clear();
    QSqlQuery query(db);
    query.exec(textSql);
    ui->listWidgetCounty->addItem("Все");
    while (query.next()) {
        QString name = query.value(0).toString();
        ui->listWidgetCounty->addItem(name);
    }
    if(this->lvl){
         ui->tableView->editTriggers();
    }
    db.close();
}

void MainWindow::on_pushButton_clicked()
{
    DialogAdd *w = new DialogAdd;
    w->show();
    return;
}
