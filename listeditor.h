#ifndef _LISTEDITOR_H_
#define _LISTEDITOR_H_

#include <QWidget>
#include "listdata.h"
#include <QModelIndex>

class QLabel;
class ListEditor : public QWidget {
	Q_OBJECT
public:
    ListEditor(const BookItem &item, QWidget *parent = 0);
	virtual ~ListEditor();

    void setBookItem(const BookItem &);
    const BookItem& getBookItem() const;

signals:
	void finished();

protected:
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);

private:
    BookItem item;
	QLabel *label;
};

#endif

