#include "contextmenuactionscontainer.h"

ContextMenuActionsContainer::ContextMenuActionsContainer(QMenuBar *menuBar)
    : BaseActionsContainer(menuBar)
{}

Command *ContextMenuActionsContainer::addAction(QString actionName, QUuid group)
{
    return nullptr;
}

Command *ContextMenuActionsContainer::addMenu(IActionsContainer *menu, QUuid group)
{
    return nullptr;
}

Command *ContextMenuActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

void ContextMenuActionsContainer::deleteMenu(Command *menu) {}

void ContextMenuActionsContainer::deleteAction(Command *action) {}
