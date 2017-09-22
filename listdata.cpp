#include "listdata.h"
#include <QDebug>

BookItem::BookItem()
{
}

void BookItem::clear()
{
	title.clear();
	pixmap.clear();
	content.clear();
}

void BookItem::setData(const QMap<QString, QString> &map)
{
	title = map.value("title");
	pixmap = map.value("pixmap");
	content = map.value("content");
    this->map = map;
}

bool BookItem::operator == (const BookItem &other) const
{
	return title == other.title &&
		pixmap == other.pixmap &&
		content == other.content;
}

void BookItem::operator = (const BookItem &other)
{
	title = other.title;
	pixmap = other.pixmap;
	content = other.content;
}

bool BookItem::isValid()
{
    return !title.isEmpty();
}

const QMap<QString, QString> BookItem::getData() const
{
    return map;
}

void BookItem::paint(QPainter *painter, const QRect &rect)
{
	//qDebug() << "BookItem" << __func__ << "rect" << rect << "pix" << pixmap;
	QPixmap pix(pixmap);
	painter->drawPixmap(rect, pix);	
}

