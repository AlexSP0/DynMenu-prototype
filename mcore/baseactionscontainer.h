#ifndef BASEACTIONSCONTAINER_H
#define BASEACTIONSCONTAINER_H

#include <QObject>

#include "iactionscontainer.h"

class BaseActionsContainer : public IActionsContainer
{
public:
    BaseActionsContainer(QMenuBar *menuBar);
    virtual ~BaseActionsContainer();

    QUuid getId();
    QMenuBar *getMenu();
    OnAllDisabledBehavior getAllDisableBehavior();

    virtual void setDefaultBehavior() override;
    virtual Command *addAction(QString actionName, QUuid group) override;
    virtual Command *addMenu(IActionsContainer *menu, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual void deleteMenu(Command *menu) override;
    virtual void deleteAction(Command *action) override;

private:
    QUuid m_id;
    QMenuBar *m_menuBar;
    QList<Command> m_actions;

    OnAllDisabledBehavior m_disableBehavior;

    // IActionsContainer interface
};

#endif // BASEACTIONSCONTAINER_H
