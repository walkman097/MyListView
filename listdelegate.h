#ifndef LISTDELEGATE_H
#define LISTDELEGATE_H

#include <QStyledItemDelegate>
#define PIXMAP   (Qt::UserRole + 1)
#define TITLE    (Qt::UserRole + 2)
#define CONTENT  (Qt::UserRole + 3)

class ListDelegate : public QStyledItemDelegate {
	Q_OBJECT
public:
    QWidget* createEditor(QWidget *,const QStyleOptionViewItem &, const QModelIndex &) const;
    void paint(QPainter *, const QStyleOptionViewItem &, const QModelIndex &) const;
    void setEditorData(QWidget *, const QModelIndex &) const;
    void setModelData(QWidget *, QAbstractItemModel *, const QModelIndex &) const;
    QSize sizeHint(const QStyleOptionViewItem &, const QModelIndex &) const;
    void updateEditorGeometry(QWidget *,const QStyleOptionViewItem &, const QModelIndex &) const;

};

#endif // LISTDELEGATE_H
