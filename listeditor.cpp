#include "listeditor.h"
#include <QtGui>

ListEditor::ListEditor(const BookItem &item, QWidget *parent)
    :QWidget(parent)
{
	setMouseTracking(true);
	setAutoFillBackground(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    label = new QLabel;
    QPixmap pixmap("images/editor.png");
    label->setPixmap(pixmap);
    label->setScaledContents(true);
    layout->addWidget(label);

    this->item = item;
    QMap<QString, QString> map = item.getData();
    map["pixmap"] = "images/editor.png";
    this->item.setData(map);
}

ListEditor::~ListEditor()
{
}

void ListEditor::setBookItem(const BookItem &item)
{
	//qDebug() << "ListEditor" << __func__ << "data" << item.getData()["pixmap"];
    this->item = item;
}

const BookItem &ListEditor::getBookItem() const
{
	//qDebug() << "ListEditor" << __func__ << "data" << item.getData()["pixmap"];
    return item;
}

void ListEditor::mouseMoveEvent(QMouseEvent *e)
{
	QWidget::mouseMoveEvent(e);
}

void ListEditor::mouseReleaseEvent(QMouseEvent *e)
{
	emit finished();
	return QWidget::mouseReleaseEvent(e);
}

