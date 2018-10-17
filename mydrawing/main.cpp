#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    //w.setWindowState(Qt::WindowMaximized);
    w.setWindowState(Qt::WindowFullScreen);

    return a.exec();
}
