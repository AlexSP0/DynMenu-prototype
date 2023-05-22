#include <QDebug>

#include "basemenumanager.h"

BaseMenuManager::BaseMenuManager() {}

BaseMenuManager::~BaseMenuManager() {}

std::weak_ptr<IActionsContainer> BaseMenuManager::addMenu(QMenu *menu, IActionsContainer *container)
{
    auto it = m_containersMap.find(container->getId());

    if (it == m_containersMap.end())
    {
        return std::weak_ptr<IActionsContainer>();
    }

    return it->second->addMenu(menu, QUuid());
}

bool BaseMenuManager::deleteMenu(IActionsContainer *menu, IActionsContainer *container)
{
    return m_containersMap[container->getId()]->deleteMenu(menu->getId());
}

std::weak_ptr<IActionsContainer> BaseMenuManager::getMenu(QUuid id)
{
    for (auto currentContainer : m_containersMap)
    {
        std::weak_ptr<IActionsContainer> result = currentContainer.second;
        if (auto tmp = result.lock())
        {
            if (tmp->getId() == id)
            {
                return result;
            }
        }
    }

    return std::weak_ptr<IActionsContainer>();
}

std::weak_ptr<Command> BaseMenuManager::addAction(QAction *action, IActionsContainer *container)
{
    auto it = m_containersMap.find(container->getId());

    if (it == m_containersMap.end())
    {
        return std::weak_ptr<Command>();
    }

    return it->second->addAction(action, QUuid());
}

bool BaseMenuManager::deleteAction(IActionsContainer *action, IActionsContainer *container)
{
    return m_containersMap[container->getId()]->deleteAction(action->getId());
}

std::weak_ptr<Command> BaseMenuManager::getAction(QUuid id, IActionsContainer *container)
{
    for (auto currentContainer : m_containersMap)
    {
        std::weak_ptr<IActionsContainer> result = currentContainer.second;
        if (auto tmp = result.lock())
        {
            if (tmp->getId() == container->getId())
            {
                return tmp->getActionById(id);
            }
        }
    }

    return std::weak_ptr<Command>();
}

std::weak_ptr<IActionsContainer> BaseMenuManager::registerMenuBar(QMenuBar *menuBar)
{
    if (!menuBar)
    {
        return std::weak_ptr<IActionsContainer>();
    }

    std::shared_ptr<IActionsContainer> newMenuBar = std::make_unique<UiContainer>(menuBar);

    connect(menuBar, &QObject::destroyed, this, &BaseMenuManager::menuBarDestroyed);

    m_containersMap[newMenuBar->getId()] = newMenuBar;

    return newMenuBar;
}

std::weak_ptr<IActionsContainer> BaseMenuManager::registerMenu(QMenu *menu)
{
    if (!menu)
    {
        return std::weak_ptr<IActionsContainer>();
    }

    std::shared_ptr<IActionsContainer> newMenu = std::make_unique<UiContainer>(menu);

    connect(menu, &QObject::destroyed, this, &BaseMenuManager::menuDestroyed);

    m_containersMap[newMenu->getId()] = newMenu;

    return newMenu;
}

std::weak_ptr<IActionsContainer> BaseMenuManager::registerToolBar(QToolBar toolbar)
{
    return std::weak_ptr<IActionsContainer>();
}

bool BaseMenuManager::unRegisterMenuBar(IActionsContainer *menuBar)
{
    return unRegisterMenu(menuBar);
}

bool BaseMenuManager::unRegisterMenu(IActionsContainer *menu)
{
    auto it = m_containersMap.find(menu->getId());

    if (it != m_containersMap.end())
    {
        m_containersMap.erase(it);

        return true;
    }

    return false;
}

bool BaseMenuManager::unRegisterToolBar(IActionsContainer *toolbar)
{
    return false;
}

std::weak_ptr<IActionsContainer> BaseMenuManager::getMenuById(QUuid id)
{
    auto it = m_containersMap.find(id);

    if (it != m_containersMap.end())
    {
        return it->second;
    }

    return std::weak_ptr<IActionsContainer>();
}

std::weak_ptr<Command> BaseMenuManager::getActionById(QUuid id, IActionsContainer *containerId)
{
    if (!containerId)
    {
        return std::weak_ptr<Command>();
    }

    auto it = m_containersMap.find(containerId->getId());

    if (it != m_containersMap.end())
    {
        return it->second->getActionById(id);
    }

    return std::weak_ptr<Command>();
}

void BaseMenuManager::menuBarDestroyed(QObject *menuBar)
{
    QMenuBar *deletedMenuBar = static_cast<QMenuBar *>(menuBar);

    if (!deletedMenuBar)
    {
        return;
    }

    for (auto currentElement : m_containersMap)
    {
        auto currentUuid              = currentElement.first;
        auto currentIActionsContainer = currentElement.second;

        if (currentIActionsContainer->getMenuBar() == deletedMenuBar)
        {
            m_containersMap.erase(currentUuid);
            return;
        }
    }

    qWarning() << "Can't find QMenuBar for deletion!";
}

void BaseMenuManager::menuDestroyed(QObject *menu)
{
    QMenu *deletedMenu = static_cast<QMenu *>(menu);

    if (!deletedMenu)
    {
        return;
    }

    for (auto currentElement : m_containersMap)
    {
        auto currentUuid              = currentElement.first;
        auto currentIActionsContainer = currentElement.second;

        if (currentIActionsContainer->getMenu() == deletedMenu)
        {
            m_containersMap.erase(currentUuid);
            return;
        }
    }

    qWarning() << "Can't find QMenu for deletion!";
}

void BaseMenuManager::toolBarDestroyed(QObject *toolBar) {}
