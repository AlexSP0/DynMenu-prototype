#include "menuactionscontainer.h"

#include <QDebug>

MenuActionsContainer::MenuActionsContainer(QString title)
    : m_id(QUuid::createUuid())
    , m_menu(std::make_unique<QMenu>())
    , m_disableBehavior(OnAllDisabledBehavior::Hide)
{
    m_menu->setTitle(title);
}

MenuActionsContainer::~MenuActionsContainer() {}

QUuid MenuActionsContainer::getId()
{
    return m_id;
}

QMenu *MenuActionsContainer::getMenu()
{
    return m_menu.get();
}

IActionsContainer::OnAllDisabledBehavior MenuActionsContainer::getAllDisableBehavior()
{
    return m_disableBehavior;
}

void MenuActionsContainer::setDefaultBehavior() {}

Command *MenuActionsContainer::addAction(QAction *action, QUuid group)
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

    return newCommand.get();
}

IActionsContainer *MenuActionsContainer::addMenu(QString title, QUuid group)
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

    return newMenu.get();
}

Command *MenuActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

bool MenuActionsContainer::deleteMenu(QUuid id)
{
    return removeMenu(id);
}

bool MenuActionsContainer::deleteAction(QUuid id)
{
    return removeAction(id);
}

bool MenuActionsContainer::appendAction(std::shared_ptr<Command> command, QUuid group)
{
    Q_UNUSED(group)

    if (!command)
    {
        return false;
    }

    connect(command->getAction(), &QObject::destroyed, this, &MenuActionsContainer::destroyCommand);

    m_actions.insert(std::pair{command->getId(), command});

    m_menu->addAction(command->getAction());

    return true;
}

bool MenuActionsContainer::removeAction(QUuid id)
{
    auto it = m_actions.find(id);

    if (it != m_actions.end())
    {
        m_menu->removeAction(it->second.get()->getAction());

        m_actions.erase(it);

        return true;
    }

    return false;
}

bool MenuActionsContainer::appendMenu(std::shared_ptr<IActionsContainer> menu, QUuid group)
{
    Q_UNUSED(group)

    if (!menu)
    {
        return false;
    }

    connect(menu->getMenu(), &QObject::destroyed, this, &MenuActionsContainer::destroyMenu);

    m_menus.insert(std::pair{menu->getId(), menu});

    m_menu->addMenu(menu->getMenu());

    return true;
}

bool MenuActionsContainer::removeMenu(QUuid id)
{
    auto it = m_menus.find(id);

    if (it != m_menus.end())
    {
        m_menu->removeAction(it->second.get()->getMenu()->menuAction());

        m_menus.erase(it);

        return true;
    }

    return false;
}

void MenuActionsContainer::destroyCommand(QObject *command)
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

void MenuActionsContainer::destroyMenu(QObject *menu)
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
