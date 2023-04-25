#include "toolbaractionscontainer.h"

ToolBarActionsContainer::ToolBarActionsContainer(QMenuBar *menuBar)
    : BaseActionsContainer(menuBar)
{}

Command *ToolBarActionsContainer::addAction(QString actionName, QUuid group)
{
    return nullptr;
}

Command *ToolBarActionsContainer::addMenu(IActionsContainer *menu, QUuid group)
{
    return nullptr;
}

Command *ToolBarActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

void ToolBarActionsContainer::deleteMenu(Command *menu) {}

void ToolBarActionsContainer::deleteAction(Command *action) {}
