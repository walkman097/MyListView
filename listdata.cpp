#include "listdata.h"
#include <QDebug>

BookItem::BookItem()
{
}

void BookItem::clear()
{
}

void BookItem::setData(const QMap<QString, QString> &map)
{
    this->map = map;
}

bool BookItem::operator == (const BookItem &other) const
{
	return map == other.map;
}

void BookItem::operator = (const BookItem &other)
{
	map = other.map;
}

bool BookItem::isValid()
{
    return !map.isEmpty();
}

const QMap<QString, QString> BookItem::getData() const
{
    return map;
}

void BookItem::paint(QPainter *painter, const QRect &rect)
{
	QPixmap pix(map["pixmap"]);
	//qDebug() << "BookItem" << __func__ << "rect" << rect << "pix" << map["pixmap"];
	painter->drawPixmap(rect, pix);
}

