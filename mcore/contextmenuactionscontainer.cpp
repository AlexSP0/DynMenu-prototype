#include "contextmenuactionscontainer.h"

ContextMenuActionsContainer::ContextMenuActionsContainer(QString title)
    : IActionsContainer()
{}

Command *ContextMenuActionsContainer::addAction(QAction *action, QUuid group)
{
    return nullptr;
}

IActionsContainer *ContextMenuActionsContainer::addMenu(QString title, QUuid group)
{
    return nullptr;
}

Command *ContextMenuActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

bool ContextMenuActionsContainer::deleteMenu(QUuid id)
{
    return false;
}

bool ContextMenuActionsContainer::deleteAction(QUuid id)
{
    return false;
}
