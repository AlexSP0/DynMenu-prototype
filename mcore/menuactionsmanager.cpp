#include "menuactionsmanager.h"

MenuActionsManager::MenuActionsManager(QMainWindow *mainWindow)
    : m_mainWindow(mainWindow)
    , m_menuBar(mainWindow->menuBar())
{}
/*
 *
 */

Command *MenuActionsManager::registerAction(QString actionName, Command *menu)
{
    auto currentCommand = std::make_shared<Command>(std::make_shared<QAction>(actionName));

    if (!insertAction(currentCommand.get(), menu))
    {
        return nullptr;
    }

    m_actions.insert(currentCommand->id, currentCommand);

    return currentCommand.get();
}

Command *MenuActionsManager::registerMenu(QString menuName, Command *menu)
{
    auto currentCommand = std::make_shared<Command>(std::make_shared<QMenu>(menuName));

    if (!insertAction(currentCommand.get(), menu))
    {
        return nullptr;
    }

    m_actions.insert(currentCommand->id, currentCommand);

    return currentCommand.get();
}

bool MenuActionsManager::unregisterAction(Command *action)
{
    auto it = m_actions.find(action->id);

    if (it == m_actions.end())
    {
        return false;
    }

    if (removeAction(action))
    {
        m_actions.remove(action->id);

        return true;
    }
    return false;
}

bool MenuActionsManager::unregisterMenu(Command *command)
{
    return unregisterAction(command);
}

bool MenuActionsManager::insertAction(Command *action, Command *destination)
{
    if (!destination)
    {
        m_menuBar->addAction(action->getAction());

        return true;
    }
    for (QAction *currentAction : m_menuBar->actions())
    {
        QMenu *currentMenu = currentAction->menu();

        if (currentMenu)
        {
            if (currentAction == destination->m_menu->menuAction())
            {
                currentMenu->addAction(action->getAction());

                return true;
            }
            else
            {
                return insertActionInMenu(action, destination->m_menu.get(), currentMenu);
            }
        }
    }
    return false;
}

bool MenuActionsManager::insertActionInMenu(Command *action, QMenu *destination, QMenu *currentSearchMenu)
{
    for (QAction *currentAction : currentSearchMenu->actions())
    {
        QMenu *currentMenu = currentAction->menu();

        if (currentMenu)
        {
            if (destination == currentMenu)
            {
                currentMenu->addAction(action->getAction());
                return true;
            }
            else
            {
                return insertActionInMenu(action, destination, currentMenu);
                ;
            }
        }
    }
    return false;
}

bool MenuActionsManager::removeAction(Command *action)
{
    for (QAction *currentAction : m_menuBar->actions())
    {
        QMenu *currentMenu = currentAction->menu();

        if (!currentMenu)
        {
            if (action->getAction() == currentAction)
            {
                m_menuBar->removeAction(currentAction);
                return true;
            }
        }
        else
        {
            return removeActionInMenu(action, currentMenu);
        }
    }

    return false;
}

bool MenuActionsManager::removeActionInMenu(Command *action, QMenu *currentSearchMenu)
{
    for (QAction *currentAction : currentSearchMenu->actions())
    {
        QMenu *currentMenu = currentAction->menu();

        if (!currentMenu)
        {
            if (currentAction == action->getAction())
            {
                currentSearchMenu->removeAction(currentAction);
                m_mainWindow->repaint();
                return true;
            }
        }
        else
        {
            if (currentAction == action->getAction())
            {
                currentSearchMenu->removeAction(currentAction);
            }

            removeActionInMenu(action, currentMenu);
        }
    }

    return false;
}
