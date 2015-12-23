#include "mainwindow.h"
#include <QApplication>
//#include <QGridLayout>
#include <QtCore>
#include <QtWidgets>
//#include <QGroupBox>

#include "verticallabel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main_window;


    main_window.show();
    return a.exec();
}
