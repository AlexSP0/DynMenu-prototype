#include "menuactionscontainer.h"

MenuActionsContainer::MenuActionsContainer(QMenuBar *menuBar)
    : BaseActionsContainer(menuBar)
{}

Command *MenuActionsContainer::addAction(QString actionName, QUuid group)
{
    return nullptr;
}

Command *MenuActionsContainer::addMenu(IActionsContainer *menu, QUuid group)
{
    return nullptr;
}

Command *MenuActionsContainer::addSeparator(QUuid group)
{
    return nullptr;
}

void MenuActionsContainer::deleteMenu(Command *menu) {}

void MenuActionsContainer::deleteAction(Command *action) {}
