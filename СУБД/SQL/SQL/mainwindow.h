#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QListWidgetItem>
#include "dialogadd.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(int lvl, QWidget *parent = nullptr);
    ~MainWindow();
    int lvl = 0;

private slots:
    void on_listWidgetState_itemChanged(QListWidgetItem *item);

    void on_listWidgetCounty_clicked(const QModelIndex &index);

    void on_listWidgetState_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
