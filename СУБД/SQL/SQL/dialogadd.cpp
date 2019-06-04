#include "dialogadd.h"
#include "ui_dialogadd.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlTableModel>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QStandardItem>

DialogAdd::DialogAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
}

DialogAdd::~DialogAdd()
{
    delete ui;
}


void DialogAdd::on_pushButton_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO demograf(censustract, state, county, totalpop, men, women) values(:censustract,:state,:county,:state,:totalpop,:men,:women)");
    query.bindValue(":censustract",ui->id->text());
    query.bindValue(":state",ui->id->text());
    query.bindValue(":county",ui->id->text());
    query.bindValue(":women",ui->id->text());
    query.bindValue(":totalpop",ui->id->text());
    query.bindValue(":men",ui->id->text());
}
