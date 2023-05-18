#include "menuactionscontainer.h"
#include "basemenuactionscontainer.h"

#include <QDebug>

MenuActionsContainer::MenuActionsContainer(QMenu *menu)
    : m_id(QUuid::createUuid())
    , m_container(new BaseMenuActionsContainer())
    , m_menu(menu)
{}

MenuActionsContainer::~MenuActionsContainer()
{
    delete m_container;
}

QUuid MenuActionsContainer::getId()
{
    return m_id;
}

QMenu *MenuActionsContainer::getMenu()
{
    return m_menu;
}

std::weak_ptr<Command> MenuActionsContainer::addAction(QAction *action, QUuid group)
{
    std::shared_ptr<Command> newCommand = m_container->appendAction(action, group);

    if (!newCommand)
    {
        return std::weak_ptr<Command>();
    }

    connect(action, &QObject::destroyed, this, &MenuActionsContainer::destroyCommand);

    m_menu->addAction(newCommand->getAction());

    return newCommand;
}

std::weak_ptr<IActionsContainer> MenuActionsContainer::addMenu(QMenu *menu, QUuid group)
{
    std::shared_ptr<IActionsContainer> newMenu = m_container->appendMenu(menu, group);

    if (!newMenu)
    {
        return std::weak_ptr<IActionsContainer>();
    }

    connect(newMenu->getMenu(), &QObject::destroyed, this, &MenuActionsContainer::destroyMenu);

    m_menu->addMenu(newMenu->getMenu());

    return newMenu;
}

Command *MenuActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

bool MenuActionsContainer::deleteMenu(QUuid id)
{
    std::shared_ptr<IActionsContainer> menu = m_container->getMenuContainer(id);
    if (!menu)
    {
        return false;
    }

    m_menu->removeAction(menu->getMenu()->menuAction());

    m_container->removeMenu(id);

    return true;
}

bool MenuActionsContainer::deleteAction(QUuid id)
{
    std::shared_ptr<Command> command = m_container->getActionContainer(id);

    if (!command)
    {
        return false;
    }

    m_menu->removeAction(command->getAction());

    m_container->removeAction(id);

    return true;
}

void MenuActionsContainer::destroyCommand(QObject *command)
{
    auto commandContainer = m_container->getActionContainerByPtr(command);

    if (commandContainer)
    {
        m_menu->removeAction(commandContainer->getAction());

        m_container->removeAction(commandContainer->getId());
    }

    return;
}

void MenuActionsContainer::destroyMenu(QObject *menu)
{
    auto menuContainer = m_container->getMenuContainerByPtr(menu);

    if (menuContainer)
    {
        m_menu->removeAction(menuContainer->getMenu()->menuAction());

        m_container->removeMenu(menuContainer->getId());
    }

    return;
}
