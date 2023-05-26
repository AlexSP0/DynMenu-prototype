#include "basemenuactionscontainer.h"

#include <QDebug>

#include <uielements/uicontainer.h>

BaseMenuActionsContainer::~BaseMenuActionsContainer() {}

std::shared_ptr<Command> BaseMenuActionsContainer::appendAction(QAction *action)
{
    if (!action)
    {
        return nullptr;
    }

    std::shared_ptr<Command> newCommand = std::make_shared<Command>(action);

    newCommand->setText(action->text());

    m_actions[newCommand->getId()] = newCommand;

    return newCommand;
}

std::shared_ptr<IActionsContainer> BaseMenuActionsContainer::appendMenu(QMenu *menu)
{
    if (!menu)
    {
        return nullptr;
    }

    std::shared_ptr<IActionsContainer> newMenu = std::make_shared<UiContainer>(menu);

    m_menus[newMenu->getId()] = newMenu;

    return newMenu;
}

bool BaseMenuActionsContainer::removeAction(QUuid id)
{
    auto it = m_actions.find(id);

    if (it != m_actions.end())
    {
        m_actions.erase(it);

        return true;
    }

    return false;
}

bool BaseMenuActionsContainer::removeMenu(QUuid id)
{
    auto it = m_menus.find(id);

    if (it != m_menus.end())
    {
        m_menus.erase(it);

        return true;
    }

    return false;
}

IBaseMenuActionsContainer::CommandsMap &BaseMenuActionsContainer::getActions()
{
    return m_actions;
}

IBaseMenuActionsContainer::MenusMap &BaseMenuActionsContainer::getMenus()
{
    return m_menus;
}

std::shared_ptr<Command> BaseMenuActionsContainer::getActionContainer(QUuid id)
{
    auto it = m_actions.find(id);
    if (it != m_actions.end())
    {
        return it->second;
    }

    return nullptr;
}

std::shared_ptr<IActionsContainer> BaseMenuActionsContainer::getMenuContainer(QUuid id)
{
    auto it = m_menus.find(id);
    if (it != m_menus.end())
    {
        return it->second;
    }

    return nullptr;
}

Command *BaseMenuActionsContainer::getActionContainerByPtr(QObject *action)
{
    QAction *currentAction = static_cast<QAction *>(action);

    for (auto &element : m_actions)
    {
        Command *currentCommand = element.second.get();

        if (currentCommand->getAction() == currentAction)
        {
            return currentCommand;
        }
    }

    return nullptr;
}

IActionsContainer *BaseMenuActionsContainer::getMenuContainerByPtr(QObject *menu)
{
    QMenu *menuPtr = static_cast<QMenu *>(menu);

    for (auto &element : m_menus)
    {
        IActionsContainer *currentMenu = element.second.get();

        if (currentMenu->getMenu() == menuPtr)
        {
            return currentMenu;
        }
    }

    return nullptr;
}
