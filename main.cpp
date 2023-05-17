#include "mainwindow.h"

#include "mcore/menubaractionscontainer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    MenuBarActionsContainer menuBar(&w);

    QMenu subMenu1("Title1");

    QMenu subMenu2("Title2");

    QMenu subMenu3("Title3");

    QMenu subMenu4("Title4");

    auto subMenu1Ptr = menuBar.addMenu(&subMenu1, QUuid());

    auto subMenu2Ptr = menuBar.addMenu(&subMenu2, QUuid());

    auto subMenu3Ptr = subMenu1Ptr->addMenu(&subMenu3, QUuid());

    auto subMenu4Ptr = subMenu3Ptr->addMenu(&subMenu4, QUuid());

    QAction subMenu1Action1("subMenu1Action1");

    QAction subAction1("subAction1");

    QAction sub4Action1("sub4Action1");

    subMenu4Ptr->addAction(&sub4Action1, QUuid());

    menuBar.addAction(&subAction1, QUuid());

    subMenu1Ptr->addAction(&subMenu1Action1, QUuid());

    w.show();

    a.exec();

    return 0;
}
