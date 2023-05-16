#include "toolbaractionscontainer.h"

ToolBarActionsContainer::ToolBarActionsContainer(QString title)
    : MenuActionsContainer(title)
{}

Command *ToolBarActionsContainer::addAction(QAction *action, QUuid group)
{
    return nullptr;
}

IActionsContainer *ToolBarActionsContainer::addMenu(QString title, QUuid group)
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
