#ifndef BASEMENUACTIONSCONTAINER_H
#define BASEMENUACTIONSCONTAINER_H

#include "ibasemenuactionscontainer.h"

#include <QObject>

class BaseMenuActionsContainer : public QObject, public IBaseMenuActionsContainer
{
    Q_OBJECT
public:
    BaseMenuActionsContainer() = default;
    virtual ~BaseMenuActionsContainer();

public:
    bool appendAction(std::shared_ptr<Command> command, QUuid group) override;
    bool appendMenu(std::shared_ptr<IActionsContainer> menu, QUuid group) override;
    bool removeAction(QUuid id) override;
    bool removeMenu(QUuid id) override;

    CommandsMap &getActions() override;
    MenusMap &getMenus() override;

    std::shared_ptr<Command> getActionContainer(QUuid id) override;
    std::shared_ptr<IActionsContainer> getMenuContainer(QUuid id) override;

    virtual Command *getActionContainerByPtr(QObject *action) override;
    virtual IActionsContainer *getMenuContainerByPtr(QObject *menu) override;

private:
    CommandsMap m_actions;
    MenusMap m_menus;
};

#endif // BASEMENUACTIONSCONTAINER_H
