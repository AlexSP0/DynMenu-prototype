#ifndef IMENUMANAGER_H
#define IMENUMANAGER_H

#include "imenumanageablewindow.h"
#include "uielements/iactionscontainer.h"

#include <QString>
#include <QToolBar>
#include <QUuid>

class IMenuManager : public QObject
{
public:
    Q_OBJECT
public:
    using ContainerMap = std::map<QUuid, std::shared_ptr<IActionsContainer>>;

    IMenuManager()          = default;
    virtual ~IMenuManager() = default;

    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, IActionsContainer *container) = 0;
    virtual bool deleteMenu(IActionsContainer *menu, IActionsContainer *container)              = 0;
    virtual std::weak_ptr<IActionsContainer> getMenu(QUuid id)                                  = 0;

    virtual std::weak_ptr<Command> addAction(QAction *action, IActionsContainer *container) = 0;
    virtual bool deleteAction(IActionsContainer *action, IActionsContainer *container)      = 0;
    virtual std::weak_ptr<Command> getAction(QUuid id, IActionsContainer *container)        = 0;

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
