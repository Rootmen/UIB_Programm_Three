#include "dialogauth.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogAuth *dialog = new DialogAuth;
    dialog->show();
    return a.exec();;
}
