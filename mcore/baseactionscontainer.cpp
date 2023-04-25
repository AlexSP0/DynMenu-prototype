#include "baseactionscontainer.h"

BaseActionsContainer::BaseActionsContainer(QMenuBar *menuBar)
    : m_id(QUuid::createUuid())
    , m_menuBar(menuBar)
    , m_disableBehavior(OnAllDisabledBehavior::Hide)
{}

BaseActionsContainer::~BaseActionsContainer() {}

QUuid BaseActionsContainer::getId()
{
    return m_id;
}

QMenuBar *BaseActionsContainer::getMenu()
{
    return m_menuBar;
}

IActionsContainer::OnAllDisabledBehavior BaseActionsContainer::getAllDisableBehavior()
{
    return m_disableBehavior;
}

void BaseActionsContainer::setDefaultBehavior() {}

Command *BaseActionsContainer::addAction(QString actionName, QUuid group)
{
    return nullptr;
}

Command *BaseActionsContainer::addMenu(IActionsContainer *menu, QUuid group)
{
    return nullptr;
}

Command *BaseActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

void BaseActionsContainer::deleteMenu(Command *menu) {}

void BaseActionsContainer::deleteAction(Command *action) {}
