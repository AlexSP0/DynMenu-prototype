#ifndef CONTEXTMENUACTIONSCONTAINER_H
#define CONTEXTMENUACTIONSCONTAINER_H

#include "baseactionscontainer.h"

class ContextMenuActionsContainer : public BaseActionsContainer
{
public:
    ContextMenuActionsContainer(QString title);

    virtual Command *addAction(QAction *action, QUuid group) override;
    virtual IActionsContainer *addMenu(QString title, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual bool deleteMenu(QUuid id) override;
    virtual bool deleteAction(QUuid id) override;
};

#endif // CONTEXTMENUACTIONSCONTAINER_H
