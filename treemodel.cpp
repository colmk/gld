#include "treemodel.h"
treeModel::treeModel(QObject *parent)
    : QAbstractItemModel{parent}
{

}

QModelIndex treeModel::index(int row, int column, const QModelIndex &parent) const
{
    return {};
}

QModelIndex treeModel::parent(const QModelIndex &child) const
{
    return {};

}

int treeModel::rowCount(const QModelIndex &parent) const
{
    return {};

}

int treeModel::columnCount(const QModelIndex &parent) const
{
    return {};

}

QVariant treeModel::data(const QModelIndex &index, int role) const
{
    return {};

}
