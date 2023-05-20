#ifndef IMENUMANAGER_H
#define IMENUMANAGER_H

#include "iactionscontainer.h"
#include "imenumanageablewindow.h"

#include <QString>
#include <QToolBar>
#include <QUuid>

#include <uielements/uicontainer.h>

class WindowContext;

class IMenuManager : public QObject
{
public:
    Q_OBJECT

public:
    IMenuManager()          = default;
    virtual ~IMenuManager() = default;

    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, IActionsContainer *container) = 0;
    virtual bool deleteMenu(IActionsContainer *container)                                       = 0;
    virtual std::weak_ptr<Command> addAction(QAction *action, IActionsContainer *container)     = 0;
    virtual bool deleteAction(QAction *action, IActionsContainer *container)                    = 0;

    virtual std::weak_ptr<IActionsContainer> registerMenuBar(QMenuBar *menuBar) = 0;
    virtual std::weak_ptr<IActionsContainer> registerMenu(QMenu *menu)          = 0;
    virtual std::weak_ptr<IActionsContainer> registerToolBar(QToolBar toolbar)  = 0;

    virtual bool unRegisterMenuBar(IActionsContainer *menuBar) = 0;
    virtual bool unRegisterMenu(IActionsContainer *menu)       = 0;
    virtual bool unRegisterToolBar(IActionsContainer *toolbar) = 0;

public slots:
    virtual void menuBarDestroyed(QObject *menuBar) = 0;
    virtual void menuDestroyed(QObject *menu)       = 0;
    virtual void toolBarDestroyed(QObject *toolBar) = 0;
};

#endif // IMENUMANAGER_H
