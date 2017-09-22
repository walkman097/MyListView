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
}

Widget::~Widget()
{
	delete model;
	model = NULL;
}

void Widget::update()
{
	QList<QStandardItem *> items = model->takeColumn(0);
	for (int i = 0; i < items.size(); i++) {
		QMap<QString, QString> map;
		map.insert("title", "Jindi");
		map.insert("content", "Fuck");
		map.insert("pixmap", "images/editor.png");
		BookItem book;
		book.setData(map);
		items[i]->setData(qVariantFromValue(book), PIXMAP);
		model->setItem(i, items[i]);
	}
}

void Widget::initModel()
{
    for (int i = 0; i < 5; i++) {
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

