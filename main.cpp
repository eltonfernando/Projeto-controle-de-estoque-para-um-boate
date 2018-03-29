#include "mainwindow.h"
#include <QApplication>
#include <gerente.h>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login *ob = new Login();
    ob->show();

   // MainWindow w;
   // w.show();

    return a.exec();
}
