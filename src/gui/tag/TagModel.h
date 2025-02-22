/*
 *  Copyright (C) 2018 KeePassXC Team <team@keepassxc.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_TAGMODEL_H
#define KEEPASSX_TAGMODEL_H

#include <QAbstractListModel>
#include <QSharedPointer>

class Database;

class TagModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit TagModel(QSharedPointer<Database> db, QObject* parent = nullptr);
    ~TagModel() override;

    void setDatabase(QSharedPointer<Database> db);
    const QStringList& tags() const;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private slots:
    void updateTagList();

private:
    QSharedPointer<Database> m_db;
    QStringList m_tagList;
};

#endif // KEEPASSX_TAGMODEL_H
