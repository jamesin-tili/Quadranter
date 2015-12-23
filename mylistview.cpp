#include "mylistview.h"
#include <QDebug>

MyListView::MyListView(QStringListModel *model_)
    : model(model_)
{
        setSelectionMode(QAbstractItemView::ExtendedSelection);
        setDragEnabled(true);
        setAcceptDrops(true);
        setDropIndicatorShown(true);
        setDefaultDropAction(Qt::MoveAction);
        setEditTriggers(QAbstractItemView::AnyKeyPressed |
                                QAbstractItemView::DoubleClicked);
        setModel(model);
}

MyListView::~MyListView()
{

}


void MyListView::doubleClicked(const QModelIndex &index)
{
    qDebug() << "doubleClicked" << index;
}

void MyListView::keyPressEvent(QKeyEvent *event)
{
    switch ( event->key() )
    {
    case Qt::Key_Insert:
        // Add new item below current
//        qDebug() << "insert";
    {
        int row = currentIndex().row() +1;
        model->insertRows(row,1);
        QModelIndex index = model->index(row);
        setCurrentIndex(index);
        edit(index);
    }
        break;

    case Qt::Key_Delete:
        // Delete current item
//        qDebug() << "delete";
        {
        int row = currentIndex().row();
        model->removeRow(row);
        if (row < model->rowCount())
            setCurrentIndex(model->index(row));
        else
            setCurrentIndex(model->index(row-1));
        }
        break;

    default:
//        event->ignore();
        // Pass to parent
        QListView::keyPressEvent(event);
        break;
    }
}
