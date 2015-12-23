#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QListView>
#include <QKeyEvent>
#include <QStringListModel>

class MyListView : public QListView
{
public:
    MyListView(QStringListModel *model_);
    ~MyListView();

private slots:
    void doubleClicked(const QModelIndex &index);
    void keyPressEvent(QKeyEvent *event);

private:
    QStringListModel *model;

};

#endif // MYLISTVIEW_H
