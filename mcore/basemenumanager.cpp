#include "basemenumanager.h"

BaseMenuManager::BaseMenuManager() {}

IActionsContainer *BaseMenuManager::createMenu(QString &menuName, QUuid group)
{
    return nullptr;
}

bool BaseMenuManager::deleteMenu(IActionsContainer *menuContainer)
{
    return false;
}

QUuid BaseMenuManager::registerWindow(QWidget *window)
{
    return QUuid::createUuid();
}

bool BaseMenuManager::unregisterWindow(QUuid *windowId)
{
    return false;
}
