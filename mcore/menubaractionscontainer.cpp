#include "menubaractionscontainer.h"
#include "menuactionscontainer.h"

MenuBarActionsContainer::MenuBarActionsContainer(QMainWindow *window)
    : IActionsContainer()
    , m_container(new BaseMenuActionsContainer())
    , m_id(QUuid::createUuid())
    , m_menuBar(window->menuBar())
    , m_window(window)
{}

MenuBarActionsContainer::~MenuBarActionsContainer()
{
    delete m_container;
}

std::shared_ptr<Command> MenuBarActionsContainer::addAction(QAction *action, QUuid group)
{
    if (!action)
    {
        return nullptr;
    }

    std::shared_ptr<Command> newCommand = std::make_shared<Command>(action);

    newCommand->setText(action->text());

    if (!m_container->appendAction(newCommand, group))
    {
        return nullptr;
    }

    connect(action, &QObject::destroyed, this, &MenuBarActionsContainer::destroyCommand);

    m_menuBar->addAction(newCommand->getAction());

    return newCommand;
}

std::shared_ptr<IActionsContainer> MenuBarActionsContainer::addMenu(QMenu *menu, QUuid group)
{
    if (!menu)
    {
        return nullptr;
    }

    std::shared_ptr<IActionsContainer> newMenu = std::make_shared<MenuActionsContainer>(menu);

    if (!m_container->appendMenu(newMenu, group))
    {
        return nullptr;
    }

    connect(newMenu->getMenu(), &QObject::destroyed, this, &MenuBarActionsContainer::destroyMenu);

    m_menuBar->addMenu(newMenu->getMenu());

    return newMenu;
}

Command *MenuBarActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

bool MenuBarActionsContainer::deleteMenu(QUuid id)
{
    std::shared_ptr<IActionsContainer> menu = m_container->getMenuContainer(id);
    if (!menu)
    {
        return false;
    }

    m_menuBar->removeAction(menu->getMenu()->menuAction());

    m_container->removeMenu(id);

    return true;
}

bool MenuBarActionsContainer::deleteAction(QUuid id)
{
    std::shared_ptr<Command> command = m_container->getActionContainer(id);

    if (!command)
    {
        return false;
    }

    m_menuBar->removeAction(command->getAction());

    m_container->removeAction(id);

    return true;
}

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
    return m_menuBar;
}

void MenuBarActionsContainer::destroyCommand(QObject *command)
{
    auto commandContainer = m_container->getActionContainerByPtr(command);

    if (commandContainer)
    {
        m_menuBar->removeAction(commandContainer->getAction());

        m_container->removeAction(commandContainer->getId());
    }

    return;
}

void MenuBarActionsContainer::destroyMenu(QObject *menu)
{
    auto menuContainer = m_container->getMenuContainerByPtr(menu);

    if (menuContainer)
    {
        m_menuBar->removeAction(menuContainer->getMenu()->menuAction());

        m_container->removeMenu(menuContainer->getId());
    }

    return;
}
