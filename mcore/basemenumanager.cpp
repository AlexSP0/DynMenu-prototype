#include <QDebug>

#include "basemenumanager.h"

BaseMenuManager::BaseMenuManager() {}

BaseMenuManager::~BaseMenuManager() {}

std::weak_ptr<IActionsContainer> BaseMenuManager::addMenu(QMenu *menu, IActionsContainer *container)
{
    return std::weak_ptr<IActionsContainer>();
}

bool BaseMenuManager::deleteMenu(IActionsContainer *container)
{
    return false;
}

std::weak_ptr<IActionsContainer> BaseMenuManager::addAction(QAction *action, IActionsContainer *container)
{
    return std::weak_ptr<IActionsContainer>();
}

bool BaseMenuManager::deleteAction(QAction *action, IActionsContainer *container)
{
    return false;
}

std::weak_ptr<IActionsContainer> BaseMenuManager::registerMenuBar(QMenuBar *menuBar)
{
    return std::weak_ptr<IActionsContainer>();
}

std::weak_ptr<IActionsContainer> BaseMenuManager::registerMenu(QMenu *menu)
{
    return std::weak_ptr<IActionsContainer>();
}

std::weak_ptr<IActionsContainer> BaseMenuManager::registerToolBar(QToolBar toolbar)
{
    return std::weak_ptr<IActionsContainer>();
}

bool BaseMenuManager::unRegisterMenuBar(IActionsContainer *menuBar)
{
    return false;
}

bool BaseMenuManager::unRegisterMenu(IActionsContainer *menu)
{
    return false;
}

bool BaseMenuManager::unRegisterToolBar(IActionsContainer *toolbar)
{
    return false;
}

void BaseMenuManager::menuBarDestroyed(QObject *menuBar) {}

void BaseMenuManager::menuDestroyed(QObject *menu) {}

void BaseMenuManager::toolBarDestroyed(QObject *toolBar) {}
