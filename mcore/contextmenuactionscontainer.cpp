#include "contextmenuactionscontainer.h"

ContextMenuActionsContainer::ContextMenuActionsContainer(QString title)
    : IActionsContainer()
{}

std::weak_ptr<Command> ContextMenuActionsContainer::addAction(QAction *action, QUuid group)
{
    return std::weak_ptr<Command>();
}

std::weak_ptr<IActionsContainer> ContextMenuActionsContainer::addMenu(QMenu *menu, QUuid group)
{
    return std::weak_ptr<IActionsContainer>();
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
