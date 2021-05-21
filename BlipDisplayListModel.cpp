
#include "BlipDisplayListModel.h"
//include "palette.h"
#include <QDebug>
#include <QString>
#include <string>
#include <iostream>

using namespace std;

int BlipDisplayListModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_blipDisplayList.size();
}

QVariant BlipDisplayListModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= (int)m_blipDisplayList.size())
        return QVariant();


    QVariant res;
    const Blip &lc = m_blipDisplayList[index.row()];
    if (role == xRole)
    {
        res = lc.x();
    }
    else if (role == yRole)
    {
        res = lc.y();
    }
    else if (role == picRole)
    {
        res = lc.pic();
    }
    else
    {
        res = QVariant();
    }
    return res;
}

Qt::ItemFlags BlipDisplayListModel::flags(const QModelIndex & index) const
{
    Q_UNUSED(index);
    return Qt::ItemIsEditable;
}

/*
 * I think this function may only be needed if QML is modifying the model.
 * drawline_update seems to be able to take the place of this function
 * when updating the model from C++.
 */
bool BlipDisplayListModel::setData(const QModelIndex & index, const QVariant &value, int role)
{
    Blip &lc = m_blipDisplayList[index.row()];
    bool changed = false;
    bool ok;


    if (role != picRole) {
        int v = value.toInt(&ok);
        if (ok) {
            if (role == xRole && lc.x() != v) {
                lc.setX(v);
                changed = true;
            }
            else if (role == yRole && lc.y() != v) {
                lc.setY(v);
                changed = true;
            }
        }
    }
    else if (role == picRole) {
        QString v = value.toString();

        if ((!v.isEmpty() || !v.isNull()) && lc.pic() != v) {
            lc.setPic(v);
            changed = true;
        }

    }
    if (changed) {
        QVector<int> roles;
        roles << role;
        emit dataChanged(index, index, roles);
    }
    return changed;
}

QHash<int, QByteArray> BlipDisplayListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[xRole] = "x";
    roles[yRole] = "y";
    roles[picRole] = "pic";
    return roles;
}


void BlipDisplayListModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, rowCount());
    m_blipDisplayList.clear();
    endRemoveRows();
}


void BlipDisplayListModel::drawBlip_update(int idx, QString pic) {
    QModelIndex mdlIdx = index(idx, 0);
    Blip &c = m_blipDisplayList[idx];
    QVector<int> roles;
    if (pic != c.pic()) {
        c.setPic(pic);
        roles << picRole;
    }
    if (roles.count() > 0) {
        emit dataChanged(mdlIdx, mdlIdx, roles);
    }
}

/* If the blip passed in is in the bluipDisplayList then return the list index */
int BlipDisplayListModel::findBlipIndexMatch(int x1, int y1, QString pic)
{
    int idx = -1;
    int i = 0;
    for (BlipDisplayList::iterator it = m_blipDisplayList.begin(); it != m_blipDisplayList.end(); it++, i++) {
        Blip &c = *it;
        if (c.x() == x1 && c.y() == y1 && c.pic() == pic) {
            idx = i;
            break;
        }
    }
    return idx;
}

void BlipDisplayListModel::drawBlip(int x1, int y1, QString & pic)
{
    int idx = findBlipIndexMatch(x1, y1, pic);
    //qDebug()<<"car pic is " << pic;
    //car pic is  "qml/ERP/pics/RadarCarSmall1.png"
    if (idx != -1) {
        // it should never get here because I call blipDisplayListModel.clear() in blipAnimation()
        drawBlip_update(idx, pic);
    } else {
        Blip c(x1, y1, pic);
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_blipDisplayList.push_back(c);
        endInsertRows();
    }
}
