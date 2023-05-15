
#include "baseactionscontainer.h"

#include <QDebug>

BaseActionsContainer::BaseActionsContainer(QString title)
    : m_id(QUuid::createUuid())
    , m_menu(std::make_unique<QMenu>())
    , m_disableBehavior(OnAllDisabledBehavior::Hide)
{
    m_menu->setTitle(title);
}

BaseActionsContainer::~BaseActionsContainer() {}

QUuid BaseActionsContainer::getId()
{
    return m_id;
}

QMenu *BaseActionsContainer::getMenu()
{
    return m_menu.get();
}

IActionsContainer::OnAllDisabledBehavior BaseActionsContainer::getAllDisableBehavior()
{
    return m_disableBehavior;
}

void BaseActionsContainer::setDefaultBehavior() {}

Command *BaseActionsContainer::addAction(QAction *action, QUuid group)
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

IActionsContainer *BaseActionsContainer::addMenu(QString title, QUuid group)
{
    if (title.isEmpty())
    {
        return nullptr;
    }

    std::shared_ptr<IActionsContainer> newMenu = std::make_shared<BaseActionsContainer>(title);

    if (!appendMenu(newMenu, group))
    {
        return nullptr;
    }

    return newMenu.get();
}

Command *BaseActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

bool BaseActionsContainer::deleteMenu(QUuid id)
{
    return removeMenu(id);
}

bool BaseActionsContainer::deleteAction(QUuid id)
{
    return removeAction(id);
}

bool BaseActionsContainer::appendAction(std::shared_ptr<Command> command, QUuid group)
{
    Q_UNUSED(group)

    if (!command)
    {
        return false;
    }

    connect(command->getAction(), &QObject::destroyed, this, &BaseActionsContainer::destroyCommand);

    m_actions.insert(std::pair{command->getId(), command});

    m_menu->addAction(command->getAction());

    return true;
}

bool BaseActionsContainer::removeAction(QUuid id)
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

bool BaseActionsContainer::appendMenu(std::shared_ptr<IActionsContainer> menu, QUuid group)
{
    Q_UNUSED(group)

    if (!menu)
    {
        return false;
    }

    connect(menu->getMenu(), &QObject::destroyed, this, &BaseActionsContainer::destroyMenu);

    m_menus.insert(std::pair{menu->getId(), menu});

    m_menu->addMenu(menu->getMenu());

    return true;
}

bool BaseActionsContainer::removeMenu(QUuid id)
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

void BaseActionsContainer::destroyCommand(QObject *command)
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

void BaseActionsContainer::destroyMenu(QObject *menu)
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
