#include <memory>

#include "basemenuactionscontainer.h"
#include "command.h"
#include "uicontainer.h"

#include "uielements/uiqmenubarelement.h"
#include "uielements/uiqmenuelement.h"

UiContainer::UiContainer(QMenuBar *menuBar)
    : m_id(QUuid::createUuid())
    , m_container(new BaseMenuActionsContainer())
{
    m_element = new UiQMenuBarElement(menuBar);
}

UiContainer::UiContainer(QMenu *menu)
    : m_id(QUuid::createUuid())
    , m_container(new BaseMenuActionsContainer())
{
    m_element = new UiQMenuElement(menu);
}

UiContainer::~UiContainer()
{
    delete m_element;
    delete m_container;
}

std::weak_ptr<Command> UiContainer::addAction(QAction *action, QUuid group)
{
    std::shared_ptr<Command> newCommand = m_container->appendAction(action, group);

    if (!newCommand)
    {
        return std::weak_ptr<Command>();
    }

    connect(action, &QObject::destroyed, this, &UiContainer::destroyCommand);

    m_element->addAction(newCommand->getAction());

    return newCommand;
}

std::weak_ptr<IActionsContainer> UiContainer::addMenu(QMenu *menu, QUuid group)
{
    std::shared_ptr<IActionsContainer> newMenu = m_container->appendMenu(menu, group);

    if (!newMenu)
    {
        return std::weak_ptr<IActionsContainer>();
    }

    connect(newMenu->getMenu(), &QObject::destroyed, this, &UiContainer::destroyMenu);

    m_element->addMenu(newMenu->getMenu());

    return newMenu;
}

Command *UiContainer::addSeparator(QUuid group)
{
    return nullptr;
}

bool UiContainer::deleteAction(QUuid id)
{
    std::shared_ptr<Command> command = m_container->getActionContainer(id);

    if (!command)
    {
        return false;
    }

    m_element->removeAction(command->getAction());

    m_container->removeAction(id);

    return true;
}

bool UiContainer::deleteMenu(QUuid id)
{
    std::shared_ptr<IActionsContainer> menu = m_container->getMenuContainer(id);

    if (!menu)
    {
        return false;
    }

    m_element->removeAction(menu->getMenu()->menuAction());

    m_container->removeMenu(id);

    return true;
}

QUuid UiContainer::getId()
{
    return m_id;
}

QMenu *UiContainer::getMenu()
{
    return m_element->getMenu();
}

QMenuBar *UiContainer::getMenuBar()
{
    return m_element->getMenuBar();
}

void UiContainer::destroyCommand(QObject *command)
{
    auto commandContainer = m_container->getActionContainerByPtr(command);

    if (commandContainer)
    {
        m_element->removeAction(commandContainer->getAction());

        m_container->removeAction(commandContainer->getId());
    }

    return;
}

void UiContainer::destroyMenu(QObject *menu)
{
    auto menuContainer = m_container->getMenuContainerByPtr(menu);

    if (menuContainer)
    {
        m_element->removeAction(menuContainer->getMenu()->menuAction());

        m_container->removeMenu(menuContainer->getId());
    }

    return;
}
