#include "mainwindow.h"

#include <mcore/basemenumanager.h>
#include <mcore/imenumanager.h>
#include <mcore/uielements/uicontainer.h>
#include <memory>
#include <QApplication>

int main(int argc, char *argv[])
{
    using WPContainer = std::weak_ptr<IActionsContainer>;

    using WPCommandContainer = std::weak_ptr<Command>;

    QApplication a(argc, argv);

    std::shared_ptr<IMenuManager> menuManager = std::make_shared<BaseMenuManager>();

    MainWindow w;

    auto menuBarContainerWP = menuManager->registerMenuBar(w.menuBar());

    QMenu subMenu1("Title1");

    QMenu subMenu2("Title2");

    QMenu subMenu3("Title3");

    QMenu subMenu4("Title4");

    QAction subAction1("subAction1");

    QAction subAction2("subAction2");

    QAction subAction3("subAction3");

    QAction subAction4("subAction4");

    WPCommandContainer subActionWPContainer;

    if (auto tmp = menuBarContainerWP.lock())
    {
        subActionWPContainer = tmp->addAction(&subAction1, QUuid());
    }

    WPContainer title1Container;

    if (auto tmp = menuBarContainerWP.lock())
    {
        title1Container = tmp->addMenu(&subMenu1, QUuid());
    }

    WPContainer title2Container;

    if (auto tmp = menuBarContainerWP.lock())
    {
        title2Container = tmp->addMenu(&subMenu2, QUuid());
    }

    WPContainer title3Container;

    if (auto tmp = title1Container.lock())
    {
        title3Container = tmp->addMenu(&subMenu3, QUuid());
    }

    WPContainer title4Container;

    if (auto tmp = title3Container.lock())
    {
        title4Container = tmp->addMenu(&subMenu4, QUuid());
    }

    WPCommandContainer subAction2WPContainer;

    if (auto tmp = title1Container.lock())
    {
        tmp->addAction(&subAction2, QUuid());
    }

    WPCommandContainer subAction3WPContainer;

    if (auto tmp = title4Container.lock())
    {
        tmp->addAction(&subAction3, QUuid());
    }

    WPCommandContainer subAction4WPContainer;

    if (auto tmp = title4Container.lock())
    {
        tmp->addAction(&subAction4, QUuid());
    }

    w.show();

    a.exec();

    return 0;
}
