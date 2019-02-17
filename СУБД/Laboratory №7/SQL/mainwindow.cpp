#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include <QtSql>
#include <QTableView>

void clearLayout(QLayout* layout, bool deleteWidgets);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db_operat = new QLabel(this);
    db_stat = new QLabel(this);
    db_path = new QLabel(this);
    db_operat->setText("| ");
    db_stat->setText("| Ожидание указания пути к базе данных");
    db_path->setText("| Путь к базе данных не указан");
    QFont font = db_operat->font();
    font.setPixelSize(10);
    db_operat->setFont(font);
    db_stat->setFont(font);
    db_path->setFont(font);
    ui->statusBar->addPermanentWidget(db_stat);
    ui->statusBar->addPermanentWidget(db_path);
    ui->statusBar->addPermanentWidget(db_operat);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/home",tr("Базы данных (*.db)"));
    db_path->setText("|  Путь к БД "+fileName);
    ui->lineEdit->setText(fileName);
    db_path_str = fileName.toUtf8().constData();
    db_stat->setText("|  Путь к БД указан начинаю чтение");
    db_operat->setText("| Подключение к базе данных");
    test_sql_conn();
}

void MainWindow::on_pushButton_2_clicked()
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(QString::fromStdString(db_path_str));
    if (!sdb.open()) {
        db_stat->setText("|  Ошибка доступа");
        db_operat->setText("| Укажите путь к БД");
        sdb.removeDatabase("QSQLITE");
        return;
    }
    db_stat->setText("|  Доступ успешно получен");
    db_operat->setText("| Запись данных");
    QSqlQuery a_query;
    QString str_insert = "INSERT INTO orang VALUES (%1, '%2','%3', '%4', '%5' , %6);",
            str = str_insert
                    .arg(ui->id_s->text())
                    .arg(ui->lat_name_s->text())
                    .arg(ui->rus_name_s->text())
                    .arg(ui->from->text())
                    .arg(ui->datap_s->text())
                    .arg(ui->status_s->text());
    bool b = a_query.exec(str);
    if (!b) {
        db_stat->setText("|  Ошибка " +a_query.lastError().databaseText());
        db_operat->setText("| Запись данных не удалась, проверьте их правильность");
        return;
        }
    sdb.removeDatabase("QSQLITE");
    update_sql_conn();

}

void MainWindow::test_sql_conn()
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(QString::fromStdString(db_path_str));
    if (!sdb.open()) {
        db_stat->setText("|  Ошибка доступа");
        db_operat->setText("| Укажите путь к БД");
        sdb.removeDatabase("QSQLITE");
        return;
    }
    db_stat->setText("|  Доступ успешно получен");
    db_operat->setText("| Чтение данных");
    sdb.removeDatabase("QSQLITE");
    update_sql_conn();
}

void MainWindow::update_sql_conn()
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(QString::fromStdString(db_path_str));
    if (!sdb.open())
    {
        db_stat->setText("|  Ошибка доступа");
        db_operat->setText("| Укажите путь к БД");
        sdb.removeDatabase("QSQLITE");
        return;
    }
    QTableView *view = new QTableView();
    QSqlTableModel *model = new QSqlTableModel();

    model->setTable("orang");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    view->setModel(model);
    ui->db_vivei->setWidget(view);
    db_stat->setText("|  Доступ успешно получен");
    db_operat->setText("| Данные прочитаны");
    sdb.removeDatabase("QSQLITE");
}


