#ifndef MYSTRINGLISTMODEL_H
#define MYSTRINGLISTMODEL_H

#include <QStringListModel>
#include <QStringList>

class MyStringListModel : public QStringListModel
{
public:
    MyStringListModel(QStringList str_list);
    ~MyStringListModel();

    Qt::ItemFlags flags(const QModelIndex &index) const;
};

#endif // MYSTRINGLISTMODEL_H
