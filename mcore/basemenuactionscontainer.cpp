#include "basemenuactionscontainer.h"

BaseMenuActionsContainer::~BaseMenuActionsContainer() {}

bool BaseMenuActionsContainer::appendAction(std::shared_ptr<Command> command, QUuid group)
{
    Q_UNUSED(group)

    if (!command)
    {
        return false;
    }

    m_actions.insert(std::pair{command->getId(), command});

    return true;
}

bool BaseMenuActionsContainer::appendMenu(std::shared_ptr<IActionsContainer> menu, QUuid group)
{
    Q_UNUSED(group)

    if (!menu)
    {
        return false;
    }

    m_menus[menu->getId()] = menu;

    return true;
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
        //!!!!!!!m_menus.erase(it);

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
