#include "menuactionsmanager.h"

MenuActionsManager::MenuActionsManager(QMainWindow *mainWindow)
    : m_mainWindow(mainWindow)
{}

Command *MenuActionsManager::registerAction(QString actionName, Command *menu)
{
    auto currentCommand = std::make_unique<Command>(std::make_unique<QAction>(actionName));

    emit addAction(currentCommand->m_action.get(), menu);

    Command *currentCommandPtr = currentCommand.get();

    m_actions.push_back(std::move(currentCommand));

    return currentCommandPtr;
}

Command *MenuActionsManager::registerMenu(QString menuName, Command *menu)
{
    auto currentCommand = std::make_unique<Command>(std::make_unique<QMenu>(menuName));

    emit addMenu(currentCommand->m_menu.get()->menuAction(), menu);

    Command *currentCommandPtr = currentCommand.get();

    m_menus.push_back(std::move(currentCommand));

    return currentCommandPtr;
}

bool MenuActionsManager::unregisterMenu(Command *command)
{
    //TO DO - do it recursive, find all children and remove from storage

    for (auto it = m_menus.begin(); it != m_menus.end(); it++)
    {
        if (*it->get() == *command)
        {
            emit removeMenu(it->get()->m_menu.get()->menuAction());
            m_menus.erase(it);
            return true;
        }
    }
    return false;
}

bool MenuActionsManager::unregisterAction(Command *command)
{
    //TO DO remove from storage and delete empty menu

    emit removeAction(command->m_action.get());
    return true;
}
