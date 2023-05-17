#include "contextmenuactionscontainer.h"

ContextMenuActionsContainer::ContextMenuActionsContainer(QString title)
    : IActionsContainer()
{}

std::shared_ptr<Command> ContextMenuActionsContainer::addAction(QAction *action, QUuid group)
{
    return nullptr;
}

std::shared_ptr<IActionsContainer> ContextMenuActionsContainer::addMenu(QMenu *menu, QUuid group)
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
