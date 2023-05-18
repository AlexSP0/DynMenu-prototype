#include "toolbaractionscontainer.h"

ToolBarActionsContainer::ToolBarActionsContainer(QMenu *menu)
    : MenuActionsContainer(menu)
{}

std::weak_ptr<Command> ToolBarActionsContainer::addAction(QAction *action, QUuid group)
{
    return std::weak_ptr<Command>();
}

std::weak_ptr<IActionsContainer> ToolBarActionsContainer::addMenu(QMenu *menu, QUuid group)
{
    return std::weak_ptr<IActionsContainer>();
}

Command *ToolBarActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

bool ToolBarActionsContainer::deleteMenu(QUuid id)
{
    return false;
}

bool ToolBarActionsContainer::deleteAction(QUuid id)
{
    return false;
}
