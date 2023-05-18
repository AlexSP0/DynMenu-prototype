#include "mainwindow.h"

#include "mcore/menubaractionscontainer.h"
#include <memory>
#include <QApplication>

int main(int argc, char *argv[])
{
    using WPMenu = std::weak_ptr<IActionsContainer>;

    using WPCommand = std::weak_ptr<Command>;

    QApplication a(argc, argv);

    MainWindow w;

    MenuBarActionsContainer menuBar(&w);

    QMenu subMenu1("Title1");

    QMenu subMenu2("Title2");

    QMenu subMenu3("Title3");

    QMenu subMenu4("Title4");

    auto subMenu1Ptr = menuBar.addMenu(&subMenu1, QUuid());

    auto subMenu2Ptr = menuBar.addMenu(&subMenu2, QUuid());

    WPMenu subMenu3Ptr;

    if (auto tmpPtr = subMenu1Ptr.lock())
    {
        subMenu3Ptr = tmpPtr->addMenu(&subMenu3, QUuid());
    }

    WPMenu subMenu4Ptr;

    if (auto tmpPtr = subMenu2Ptr.lock())
    {
        subMenu4Ptr = tmpPtr->addMenu(&subMenu4, QUuid());
    }

    QAction subAction1("subAction1");

    QAction subAction2("subAction2");

    QAction subAction3("subAction3");

    QAction subAction4("subAction4");

    auto subAction1Ptr = menuBar.addAction(&subAction1, QUuid());

    WPCommand subAction2Ptr;

    if (auto tmpPtr = subMenu2Ptr.lock())
    {
        subAction2Ptr = tmpPtr->addAction(&subAction2, QUuid());
    }

    WPCommand subAction3Ptr;

    if (auto tmpPtr = subMenu2Ptr.lock())
    {
        subAction3Ptr = tmpPtr->addAction(&subAction3, QUuid());
    }

    WPCommand subAction4Ptr;

    if (auto tmpPtr = subMenu4Ptr.lock())
    {
        subAction4Ptr = tmpPtr->addAction(&subAction4, QUuid());
    }

    w.show();

    a.exec();

    return 0;
}
