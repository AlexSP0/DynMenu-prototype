#ifndef CONTEXTMENUACTIONSCONTAINER_H
#define CONTEXTMENUACTIONSCONTAINER_H

#include "iactionscontainer.h"

class ContextMenuActionsContainer : public IActionsContainer
{
public:
    ContextMenuActionsContainer(QString title);

    virtual std::weak_ptr<Command> addAction(QAction *action, QUuid group) override;
    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual bool deleteMenu(QUuid id) override;
    virtual bool deleteAction(QUuid id) override;
};

#endif // CONTEXTMENUACTIONSCONTAINER_H
