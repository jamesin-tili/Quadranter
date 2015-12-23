#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtWidgets>
#include "mylistview.h"
#include "mystringlistmodel.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget* create_quadrant(QString title, MyListView *listView);

    QStringListModel *model;
    bool read_settings_file(QString filepath);

    QString title;
    QStringList listNames;
    QStringList list1;
    QStringList list2;
    QStringList list3;
    QStringList list4;
};

#endif // MAINWINDOW_H
