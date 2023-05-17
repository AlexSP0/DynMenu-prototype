#include "toolbaractionscontainer.h"

ToolBarActionsContainer::ToolBarActionsContainer(QMenu *menu)
    : MenuActionsContainer(menu)
{}

std::shared_ptr<Command> ToolBarActionsContainer::addAction(QAction *action, QUuid group)
{
    return nullptr;
}

std::shared_ptr<IActionsContainer> ToolBarActionsContainer::addMenu(QMenu *menu, QUuid group)
{
    return nullptr;
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
