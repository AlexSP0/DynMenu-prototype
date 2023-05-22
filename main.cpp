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

    MainWindow w(menuManager.get());

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
        subAction2WPContainer = tmp->addAction(&subAction2, QUuid());
    }

    WPCommandContainer subAction3WPContainer;

    if (auto tmp = title4Container.lock())
    {
        subAction3WPContainer = tmp->addAction(&subAction3, QUuid());
    }

    WPCommandContainer subAction4WPContainer;

    if (auto tmp = title4Container.lock())
    {
        subAction4WPContainer = tmp->addAction(&subAction4, QUuid());
    }

    QMenu contextMenu;

    QMenu contextSubMenu1("contextSubMenu1");

    QMenu contextSubMenu2("contextSubMenu2");

    QMenu contextSubMenu3("contextSubMenu3");

    QMenu contextSubMenu4("contextSubMenu4");

    QAction contextAction1("contextAction1");

    QAction contextAction2("contextAction2");

    QAction contextAction3("contextAction3");

    QAction contextAction4("contextAction4");

    WPContainer contextMenuContainer = menuManager->registerMenu(&contextMenu);

    WPContainer contextSubMenu1Container;

    if (auto tmp = contextMenuContainer.lock())
    {
        contextSubMenu1Container = tmp->addMenu(&contextSubMenu1, QUuid());
    }

    WPContainer contextSubMenu2Container;

    if (auto tmp = contextMenuContainer.lock())
    {
        contextSubMenu2Container = tmp->addMenu(&contextSubMenu2, QUuid());
    }

    WPContainer contextSubMenu3Container;

    if (auto tmp = contextSubMenu2Container.lock())
    {
        contextSubMenu3Container = tmp->addMenu(&contextSubMenu3, QUuid());
    }

    WPContainer contextSubMenu4Container;

    if (auto tmp = contextSubMenu3Container.lock())
    {
        contextSubMenu4Container = tmp->addMenu(&contextSubMenu4, QUuid());
    }

    WPCommandContainer contextAction1Container;

    if (auto tmp = contextSubMenu2Container.lock())
    {
        contextAction1Container = tmp->addAction(&contextAction1, QUuid());
    }

    WPCommandContainer contextAction2Container;

    if (auto tmp = contextSubMenu4Container.lock())
    {
        contextAction2Container = tmp->addAction(&contextAction2, QUuid());
    }

    WPCommandContainer contextAction3Container;

    if (auto tmp = contextSubMenu4Container.lock())
    {
        contextAction3Container = tmp->addAction(&contextAction3, QUuid());
    }

    WPCommandContainer contextAction4Container;

    if (auto tmp = contextSubMenu4Container.lock())
    {
        contextAction4Container = tmp->addAction(&contextAction4, QUuid());
    }

    w.show();

    a.exec();

    return 0;
}
