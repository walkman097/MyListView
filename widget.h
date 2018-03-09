#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListView>
#include <QStandardItemModel>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();
	
private:
    void initModel();

private slots:
	void operateClicked(const QStandardItem &);

private:
    QListView *listView;
    QStandardItemModel *model;
};

#endif // WIDGET_H
