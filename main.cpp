#include "mainwindow.h"

#include "mcore/baseactionscontainer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QMenuBar menuBar;

    BaseActionsContainer menu1("menu1");

    auto subMenu1Ptr = menu1.addMenu("subMenu1", QUuid());

    QAction subMenu1Action1("subMenu1Action1");

    subMenu1Ptr->addAction(&subMenu1Action1, QUuid());

    menuBar.addMenu(menu1.getMenu());

    w.setMenuBar(&menuBar);

    w.show();

    a.exec();

    return 0;
}
