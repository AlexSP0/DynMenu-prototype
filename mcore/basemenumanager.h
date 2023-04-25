#ifndef BASEMENUMANAGER_H
#define BASEMENUMANAGER_H

#include "imenumanager.h"

class BaseMenuManager : public IMenuManager
{
public:
    BaseMenuManager();

    virtual IActionsContainer *createMenu(QString &menuName, QUuid group) override;
    virtual bool deleteMenu(IActionsContainer *menuContainer) override;
    virtual QUuid registerWindow(QWidget *window) override;
    virtual bool unregisterWindow(QUuid *windowId) override;
};

#endif // BASEMENUMANAGER_H
