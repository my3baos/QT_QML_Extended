#pragma once
#include "blip.h"
#include <vector>
#include <QDebug>

#include <QAbstractListModel>







/*
When subclassing QAbstractListModel, you must provide implementations of the rowCount() and data() functions. Well behaved models also provide a headerData() implementation.

If your model is used within QML and requires roles other than the default ones provided by the roleNames() function, you must override it.

For editable list models, you must also provide an implementation of setData(), and implement the flags() function so that it returns a value containing Qt::ItemIsEditable.

Note that QAbstractListModel provides a default implementation of columnCount() that informs views that there is only a single column of items in this model.

BlipDisplayListModel is an implementation of the QAbstractListModel.
It is a listModel of the Blips. 

I want to display the list of Blips using a Repeater{} in my QML file
    
*/

class BlipDisplayListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum RectRoles {
        xRole = Qt::UserRole + 1,
        yRole,
        picRole
    };

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex & index) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role);
    void drawBlip(int x1, int y1, QString & pic);
    void clear();



private:
    void drawBlip_update(int idx, QString pic);
    int findBlipIndexMatch(int x1, int y1, QString pic);
    QHash<int, QByteArray> roleNames() const;
    typedef std::vector<Blip> BlipDisplayList;
    BlipDisplayList m_blipDisplayList;
};


