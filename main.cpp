#include "widget.h"
#include <unistd.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.resize(450, 450);
    w.show();

    return a.exec();
}
