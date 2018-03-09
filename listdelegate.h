#ifndef LISTDELEGATE_H
#define LISTDELEGATE_H

#include <QStandardItem>
#include <QStyledItemDelegate>
#define PIXMAP   (Qt::UserRole + 1)
#define TITLE    (Qt::UserRole + 2)
#define CONTENT  (Qt::UserRole + 3)
#define PRESSED  (Qt::UserRole + 3)

class ListDelegate : public QStyledItemDelegate {
	Q_OBJECT
public:
    QSize sizeHint(const QStyleOptionViewItem &, const QModelIndex &) const;
    void paint(QPainter *, const QStyleOptionViewItem &, const QModelIndex &) const;
	bool editorEvent(QEvent *, QAbstractItemModel *, const QStyleOptionViewItem &, const QModelIndex &);
	bool pixmapContains(const QRect &, const QPoint &);

signals:
	void operateClicked(const QStandardItem &);

};

#endif // LISTDELEGATE_H
