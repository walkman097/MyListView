#include "listdata.h"
#include "listdelegate.h"

#include <QtGui>
#include <QDebug>
#include <QVariant>

QSize ListDelegate::sizeHint(const QStyleOptionViewItem &/*option*/, 
		const QModelIndex &/*index*/) const
{
    return QSize(400, 150);
}

void ListDelegate::paint(QPainter *painter, 
		const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	BookItem item = qVariantValue<BookItem>(index.data(PIXMAP));
	if (item.isValid()) {
		int startX = option.rect.x();
		int endX = option.rect.x() + option.rect.width();
		int y = option.rect.y() + option.rect.height() - 5;
		painter->drawLine(QPoint(startX, y), QPoint(endX, y));
		
		QPixmap pix(item.getData()["pixmap"]);
	#if 0
		QPoint start(option.rect.width() - pix.rect().width() - 5, 
				option.rect.y() + option.rect.height() - pix.rect().height() - 5 );	
	#else
		QPoint start(option.rect.width() - pix.rect().width() - 5, option.rect.y());	
	#endif
		painter->drawPixmap(QRect(start, pix.size()), item.getData()["pixmap"]);
	}
}


bool ListDelegate::editorEvent(QEvent *event, QAbstractItemModel *m, 
		const QStyleOptionViewItem &option, const QModelIndex &index)
{
	QMouseEvent *mouseEvent = (QMouseEvent *)event;
	if (pixmapContains(option.rect, mouseEvent->pos())) {
		QStandardItemModel *model = (QStandardItemModel *)m;
		if (!mouseEvent && !model)
			return false;
		
		QStandardItem *item = model->item(index.row(), index.column());
		if (event->type() == QEvent::MouseButtonPress ) {
			item->setData(true, PRESSED);
			emit operateClicked(*item);
		} else if (event->type() == QEvent::MouseButtonRelease ) {
			item->setData(false, PRESSED);
			emit operateClicked(*item);
		}

		return true;
	}
	return QStyledItemDelegate::editorEvent(event, m, option, index);
}

bool ListDelegate::pixmapContains(const QRect &rct, const QPoint &point)
{
	qDebug() << "rect" << rct << "point" << point;
	QSize size(55, 55);
	QPoint start(rct.width() - size.width() - 5, rct.y());
	QRect pixmapRect(start, QSize(55, 55));
	return pixmapRect.contains(point);
}

