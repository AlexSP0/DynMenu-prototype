#ifndef TOOLBARACTIONSCONTAINER_H
#define TOOLBARACTIONSCONTAINER_H

#include "menuactionscontainer.h"

class ToolBarActionsContainer : public MenuActionsContainer
{
public:
    ToolBarActionsContainer(QMenu *menu);

    virtual std::weak_ptr<Command> addAction(QAction *action, QUuid group) override;
    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual bool deleteMenu(QUuid id) override;
    virtual bool deleteAction(QUuid id) override;
};

#endif // TOOLBARACTIONSCONTAINER_H
