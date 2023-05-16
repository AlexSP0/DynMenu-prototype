#include "menubaractionscontainer.h"
#include "menuactionscontainer.h"

MenuBarActionsContainer::MenuBarActionsContainer(QString title)
    : IActionsContainer()
    , m_id(QUuid::createUuid())
    , m_menuBar(std::make_unique<QMenuBar>())
    , m_disableBehavior(OnAllDisabledBehavior::Hide)
{}

Command *MenuBarActionsContainer::addAction(QAction *action, QUuid group)
{
    if (!action)
    {
        return nullptr;
    }

    std::shared_ptr<Command> newCommand = std::make_shared<Command>(action);

    newCommand->setText(action->text());

    if (!appendAction(newCommand, group))
    {
        return nullptr;
    }

    m_menuBar->addAction(newCommand->getAction());

    return newCommand.get();
}

IActionsContainer *MenuBarActionsContainer::addMenu(QString title, QUuid group)
{
    if (title.isEmpty())
    {
        return nullptr;
    }

    std::shared_ptr<IActionsContainer> newMenu = std::make_shared<MenuActionsContainer>(title);

    if (!appendMenu(newMenu, group))
    {
        return nullptr;
    }

    //TO DO connect signal DESTROYED

    m_menuBar->addMenu(newMenu->getMenu());

    return newMenu.get();
}

Command *MenuBarActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

bool MenuBarActionsContainer::deleteMenu(QUuid id)
{
    auto it = m_menus.find(id);

    if (it != m_menus.end())
    {
        m_menuBar->removeAction(it->second.get()->getMenu()->menuAction());

        return removeMenu(id);
    }

    return false;
}

bool MenuBarActionsContainer::deleteAction(QUuid id)
{
    auto it = m_actions.find(id);
    if (it != m_actions.end())
    {
        m_menuBar->removeAction(it->second.get()->getAction());

        return removeAction(id);
    }

    return false;
}

void MenuBarActionsContainer::setDefaultBehavior() {}

QMenu *MenuBarActionsContainer::getMenu()
{
    return nullptr;
}

QUuid MenuBarActionsContainer::getId()
{
    return m_id;
}

QMenuBar *MenuBarActionsContainer::getMenuBar()
{
    return m_menuBar.get();
}

bool MenuBarActionsContainer::appendAction(std::shared_ptr<Command> command, QUuid group)
{
    Q_UNUSED(group)

    if (!command)
    {
        return false;
    }

    connect(command->getAction(), &QObject::destroyed, this, &MenuBarActionsContainer::destroyCommand);

    m_actions.insert(std::pair{command->getId(), command});

    return true;
}

bool MenuBarActionsContainer::removeAction(QUuid id)
{
    auto it = m_actions.find(id);

    if (it != m_actions.end())
    {
        m_actions.erase(it);

        return true;
    }

    return false;
}

bool MenuBarActionsContainer::appendMenu(std::shared_ptr<IActionsContainer> menu, QUuid group)
{
    Q_UNUSED(group)

    if (!menu)
    {
        return false;
    }

    connect(menu->getMenu(), &QObject::destroyed, this, &MenuBarActionsContainer::destroyMenu);

    m_menus.insert(std::pair{menu->getId(), menu});

    return true;
}

bool MenuBarActionsContainer::removeMenu(QUuid id)
{
    auto it = m_menus.find(id);

    if (it != m_menus.end())
    {
        m_menus.erase(it);

        return true;
    }

    return false;
}

void MenuBarActionsContainer::destroyCommand(QObject *command)
{
    QAction *currentAction = static_cast<QAction *>(command);

    for (auto &element : m_actions)
    {
        Command *currentCommand = element.second.get();

        if (currentCommand->getAction() == currentAction)
        {
            removeAction(currentCommand->getId());
            break;
        }
    }
}

void MenuBarActionsContainer::destroyMenu(QObject *menu)
{
    IActionsContainer *currentContainer = static_cast<IActionsContainer *>(menu);

    for (auto &element : m_menus)
    {
        IActionsContainer *currentMenu = element.second.get();

        if (currentMenu->getId() == currentContainer->getId())
        {
            removeMenu(currentMenu->getId());
        }
    }
}
