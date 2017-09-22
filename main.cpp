#include "widget.h"
#include <unistd.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.resize(450, 600);
    w.show();
	w.update();

    return a.exec();
}
