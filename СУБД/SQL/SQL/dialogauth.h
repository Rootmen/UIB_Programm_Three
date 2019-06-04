#ifndef DIALOGAUTH_H
#define DIALOGAUTH_H
#include <QDialog>
#include <QAbstractButton>
#include <QDialogButtonBox>
#include <QThread>
namespace Ui {
class DialogAuth;
}

class DialogAuth : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAuth(QWidget *parent = nullptr);
    ~DialogAuth();

private slots:
    void on_aut_clicked();

    void on_abort_clicked();

private:
    Ui::DialogAuth *ui;
};

#endif // DIALOGAUTH_H
