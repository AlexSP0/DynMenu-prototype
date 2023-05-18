#ifndef IBASEMENUACTIONSCONTAINER_H
#define IBASEMENUACTIONSCONTAINER_H

#include <memory>
#include <vector>

#include "command.h"
#include "iactionscontainer.h"

class IBaseMenuActionsContainer
{
public:
    using CommandsMap = std::map<QUuid, std::shared_ptr<Command>>;
    using MenusMap    = std::map<QUuid, std::shared_ptr<IActionsContainer>>;

public:
    virtual ~IBaseMenuActionsContainer()                                            = default;
    virtual std::shared_ptr<Command> appendAction(QAction *action, QUuid group)     = 0;
    virtual std::shared_ptr<IActionsContainer> appendMenu(QMenu *menu, QUuid group) = 0;

    virtual bool removeAction(QUuid id) = 0;
    virtual bool removeMenu(QUuid id)   = 0;

    virtual CommandsMap &getActions() = 0;

    virtual MenusMap &getMenus() = 0;

    virtual std::shared_ptr<Command> getActionContainer(QUuid id)         = 0;
    virtual std::shared_ptr<IActionsContainer> getMenuContainer(QUuid id) = 0;

    virtual Command *getActionContainerByPtr(QObject *action)       = 0;
    virtual IActionsContainer *getMenuContainerByPtr(QObject *menu) = 0;
};

#endif // IBASEMENUACTIONSCONTAINER_H
