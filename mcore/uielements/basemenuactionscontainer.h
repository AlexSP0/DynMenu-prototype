#ifndef BASEMENUACTIONSCONTAINER_H
#define BASEMENUACTIONSCONTAINER_H

#include "ibasemenuactionscontainer.h"

#include <QObject>

/*!
 * \brief Implementation of IBaseMenuActionsContainer - internal object that implements operations with stored containers of menus (IActionsContainer) and commands (Commands). Used by classes that implement the IActionsContainer interface.
 *
 * Base for classes that implements the IActionsContainer interface.
 *
 */
class BaseMenuActionsContainer : public QObject, public IBaseMenuActionsContainer
{
    Q_OBJECT
public:
    BaseMenuActionsContainer() = default;
    virtual ~BaseMenuActionsContainer();

public:
    std::shared_ptr<Command> appendAction(QAction *action) override;
    std::shared_ptr<IActionsContainer> appendMenu(QMenu *menu) override;
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
