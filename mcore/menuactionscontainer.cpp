#include "menuactionscontainer.h"

MenuActionsContainer::MenuActionsContainer(QString title)
    : BaseActionsContainer(title)
{}

Command *MenuActionsContainer::addAction(QAction *action, QUuid group)
{
    return nullptr;
}

IActionsContainer *MenuActionsContainer::addMenu(QString title, QUuid group)
{
    return nullptr;
}

Command *MenuActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

bool MenuActionsContainer::deleteMenu(QUuid id)
{
    return false;
}

bool MenuActionsContainer::deleteAction(QUuid id)
{
    return false;
}
