#include "mainwindow.h"

#include "mcore/menubaractionscontainer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    MenuBarActionsContainer menuBar("MenuBar");

    auto subMenu1Ptr = menuBar.addMenu("SubMenu1", QUuid());

    auto sub1subMenu1 = subMenu1Ptr->addMenu("Sub1SubMenu1", QUuid());

    QAction subMenu1Action1("subMenu1Action1");

    subMenu1Ptr->addAction(&subMenu1Action1, QUuid());

    w.setMenuBar(menuBar.getMenuBar());

    w.show();

    a.exec();

    return 0;
}
