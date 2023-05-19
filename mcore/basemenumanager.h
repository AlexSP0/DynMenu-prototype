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
    virtual bool deleteMenu(IActionsContainer *container) override;
    virtual std::weak_ptr<IActionsContainer> addAction(QAction *action, IActionsContainer *container) override;
    virtual bool deleteAction(QAction *action, IActionsContainer *container) override;

    virtual std::weak_ptr<IActionsContainer> registerMenuBar(QMenuBar *menuBar) override;
    virtual std::weak_ptr<IActionsContainer> registerMenu(QMenu *menu) override;
    virtual std::weak_ptr<IActionsContainer> registerToolBar(QToolBar toolbar) override;

    virtual bool unRegisterMenuBar(IActionsContainer *menuBar) override;
    virtual bool unRegisterMenu(IActionsContainer *menu) override;
    virtual bool unRegisterToolBar(IActionsContainer *toolbar) override;

public slots:
    virtual void menuBarDestroyed(QObject *menuBar) override;
    virtual void menuDestroyed(QObject *menu) override;
    virtual void toolBarDestroyed(QObject *toolBar) override;

private:
    std::map<QUuid, std::shared_ptr<IActionsContainer>> m_menuBars;
    std::map<QUuid, std::shared_ptr<IActionsContainer>> m_menus;
    std::map<QUuid, std::shared_ptr<IActionsContainer>> m_contecMenus;
};

#endif // BASEMENUMANAGER_H
