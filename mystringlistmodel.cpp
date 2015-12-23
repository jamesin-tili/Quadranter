#include "mystringlistmodel.h"

MyStringListModel::MyStringListModel(QStringList str_list)
{
    setStringList(str_list);
}

MyStringListModel::~MyStringListModel()
{

}

Qt::ItemFlags MyStringListModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags defaultFlags = QStringListModel::flags(index);

        if (index.isValid())
            return (Qt::ItemIsDragEnabled | defaultFlags) ^ Qt::ItemIsDropEnabled;
//            return Qt::ItemIsDragEnabled | defaultFlags;
        // QFlags(0x1|0x2|0x4|0x8|0x20|0x80)
        else
            return Qt::ItemIsDropEnabled | defaultFlags;
}
