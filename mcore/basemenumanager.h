#ifndef BASEMENUMANAGER_H
#define BASEMENUMANAGER_H

#include "imenumanager.h"

#include "uielements/uicontainer.h"

class BaseMenuManager : public IMenuManager
{
public:
    BaseMenuManager();
    virtual ~BaseMenuManager();

    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, IActionsContainer *container) override;
    bool deleteMenu(IActionsContainer *menu, IActionsContainer *container) override;
    std::weak_ptr<IActionsContainer> getMenu(QUuid id) override;

    virtual std::weak_ptr<Command> addAction(QAction *action, IActionsContainer *container) override;
    virtual bool deleteAction(IActionsContainer *action, IActionsContainer *container) override;
    std::weak_ptr<Command> getAction(QUuid id, IActionsContainer *container) override;

    virtual std::weak_ptr<IActionsContainer> registerMenuBar(QMenuBar *menuBar) override;
    virtual std::weak_ptr<IActionsContainer> registerMenu(QMenu *menu) override;
    virtual std::weak_ptr<IActionsContainer> registerToolBar(QToolBar toolbar) override;

    virtual bool unRegisterMenuBar(IActionsContainer *menuBar) override;
    virtual bool unRegisterMenu(IActionsContainer *menu) override;
    virtual bool unRegisterToolBar(IActionsContainer *toolbar) override;

    std::weak_ptr<IActionsContainer> getMenuById(QUuid id);
    std::weak_ptr<Command> getActionById(QUuid id, IActionsContainer *containerId);

public slots:
    virtual void menuBarDestroyed(QObject *menuBar) override;
    virtual void menuDestroyed(QObject *menu) override;
    virtual void toolBarDestroyed(QObject *toolBar) override;

private:
    ContainerMap m_containersMap;
};

#endif // BASEMENUMANAGER_H
