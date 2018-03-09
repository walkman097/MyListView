#include "widget.h"
#include "listdata.h"
#include "listdelegate.h"

#include <QtGui>
#include <QVariant>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    listView = new QListView;
    ListDelegate *delegate = new ListDelegate;
    listView->setItemDelegate(delegate);
    model = new QStandardItemModel;
    listView->setModel(model);
    initModel();
    layout->addWidget(listView);
	connect(delegate, SIGNAL(operateClicked(const QStandardItem &)), this, SLOT(operateClicked(const  QStandardItem &)));
}

Widget::~Widget()
{
	delete model;
	model = NULL;
}

void Widget::initModel()
{
    for (int i = 0; i < 10; i++) {
        QStandardItem *item = new QStandardItem;
		QMap<QString, QString> map;
		map.insert("title", "Jindi");
		map.insert("content", "Fuck");
		map.insert("pixmap", "images/head.png");
		BookItem book;
		book.setData(map);
		item->setData(qVariantFromValue(book), PIXMAP);
		model->setItem(i, item);
    }
}

void Widget::operateClicked(const QStandardItem &item)
{
	BookItem book;
	QMap<QString, QString> map;
	if (item.data(PRESSED).toBool()) {
		map.insert("title", "Jindi");
		map.insert("content", "Fuck");
		map.insert("pixmap", "images/editor.png");
		book.setData(map);
	} else {
		map.insert("title", "Jindi");
		map.insert("content", "Fuck");
		map.insert("pixmap", "images/head.png");
		book.setData(map);
	}
	model->setData(item.index(), qVariantFromValue(book), PIXMAP);
}

