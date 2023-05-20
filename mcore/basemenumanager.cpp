#include <QDebug>

#include "basemenumanager.h"

BaseMenuManager::BaseMenuManager() {}

BaseMenuManager::~BaseMenuManager() {}

std::weak_ptr<IActionsContainer> BaseMenuManager::addMenu(QMenu *menu, IActionsContainer *container)
{
    return std::weak_ptr<IActionsContainer>();
}

bool BaseMenuManager::deleteMenu(IActionsContainer *container)
{
    return false;
}

std::weak_ptr<Command> BaseMenuManager::addAction(QAction *action, IActionsContainer *container)
{
    return std::weak_ptr<Command>();
}

bool BaseMenuManager::deleteAction(QAction *action, IActionsContainer *container)
{
    return false;
}

std::weak_ptr<IActionsContainer> BaseMenuManager::registerMenuBar(QMenuBar *menuBar)
{
    if (!menuBar)
    {
        return std::weak_ptr<IActionsContainer>();
    }

    std::shared_ptr<IActionsContainer> newMenuBar = std::make_unique<UiContainer>(menuBar);

    connect(menuBar, &QObject::destroyed, this, &BaseMenuManager::menuBarDestroyed);

    m_menuBars[newMenuBar->getId()] = newMenuBar;

    return newMenuBar;
}

std::weak_ptr<IActionsContainer> BaseMenuManager::registerMenu(QMenu *menu)
{
    return std::weak_ptr<IActionsContainer>();
}

std::weak_ptr<IActionsContainer> BaseMenuManager::registerToolBar(QToolBar toolbar)
{
    return std::weak_ptr<IActionsContainer>();
}

bool BaseMenuManager::unRegisterMenuBar(IActionsContainer *menuBar)
{
    auto it = m_menuBars.find(menuBar->getId());

    if (it != m_menuBars.end())
    {
        m_menuBars.erase(it);

        return true;
    }

    return false;
}

bool BaseMenuManager::unRegisterMenu(IActionsContainer *menu)
{
    return false;
}

bool BaseMenuManager::unRegisterToolBar(IActionsContainer *toolbar)
{
    return false;
}

void BaseMenuManager::menuBarDestroyed(QObject *menuBar)
{
    QMenuBar *deletedMenuBar = static_cast<QMenuBar *>(menuBar);

    if (!deletedMenuBar)
    {
        return;
    }

    for (auto currentElement : m_menuBars)
    {
        auto currentUuid              = currentElement.first;
        auto currentIActionsContainer = currentElement.second;

        if (currentIActionsContainer->getMenuBar() == deletedMenuBar)
        {
            m_menuBars.erase(currentUuid);
            return;
        }
    }

    qWarning() << "Can't find QMenuBar for delete!";
}

void BaseMenuManager::menuDestroyed(QObject *menu) {}

void BaseMenuManager::toolBarDestroyed(QObject *toolBar) {}
