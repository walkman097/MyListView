#ifndef _LISTDATA_H_
#define _LISTDATA_H_

#include <QMap>
#include <QRect>
#include <QString>
#include <QPainter>
#include <QMetaType> 

class BookItem {
public:
	BookItem();
	
	void clear();
	bool isValid();
    const QMap<QString, QString> getData() const;
	void setData(const QMap<QString, QString> &map);

	void paint(QPainter *painter, const QRect &rect);
    void operator = (const BookItem &other);
    bool operator == (const BookItem &other) const;

private:
    QMap<QString, QString> map;
};

Q_DECLARE_METATYPE(BookItem)

#endif

