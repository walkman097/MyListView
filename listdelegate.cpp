#include "listdata.h"
#include "listeditor.h"
#include "listdelegate.h"

#include <QtGui>
#include <QDebug>
#include <QVariant>

QWidget *ListDelegate::createEditor(QWidget *parent, 
		const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	if (qVariantCanConvert<BookItem>(index.data(PIXMAP))) {
        BookItem item = qVariantValue<BookItem>(index.data(PIXMAP));
		ListEditor *widget = new ListEditor(item, parent);
		return widget;
	} else {
	    return QStyledItemDelegate::createEditor(parent, option, index);
	}
}

void ListDelegate::paint(QPainter *painter, 
		const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (qVariantCanConvert<BookItem>(index.data(PIXMAP))) {
        BookItem item = qVariantValue<BookItem>(index.data(PIXMAP));
		item.paint(painter, option.rect);
		int startX = option.rect.x();
		int endX = option.rect.x() + option.rect.width();
		int y = option.rect.y() + option.rect.height() - 5;
		painter->drawLine(QPoint(startX, y), QPoint(endX, y));
	} else {
		QStyledItemDelegate::paint(painter, option, index);
	}
}

void ListDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    ListEditor *widget = qobject_cast<ListEditor *>(editor);
    if (widget) {
        if (qVariantCanConvert<BookItem>(index.data(PIXMAP))) {
            BookItem item = qVariantValue<BookItem>(index.data(PIXMAP));
            widget->setBookItem(item);
        }
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void ListDelegate::setModelData(QWidget *editor, 
		QAbstractItemModel *model, const QModelIndex &index) const
{
    ListEditor *widget = qobject_cast<ListEditor *>(editor);
    if (widget) {
        BookItem book = widget->getBookItem();
		model->setData(index, qVariantFromValue(book), PIXMAP);
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

QSize ListDelegate::sizeHint(const QStyleOptionViewItem &/*option*/, 
		const QModelIndex &/*index*/) const
{
    return QSize(400, 150);
}

void ListDelegate::updateEditorGeometry(QWidget *editor, 
		const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	//qDebug() << "ListDelegate" << __func__ << "update Editor Geometry !!!";
    QStyledItemDelegate::updateEditorGeometry(editor, option, index);
}

