#ifndef TOOLBARACTIONSCONTAINER_H
#define TOOLBARACTIONSCONTAINER_H

#include "menuactionscontainer.h"

class ToolBarActionsContainer : public MenuActionsContainer
{
public:
    ToolBarActionsContainer(QString title);

    virtual Command *addAction(QAction *action, QUuid group) override;
    virtual IActionsContainer *addMenu(QString title, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual bool deleteMenu(QUuid id) override;
    virtual bool deleteAction(QUuid id) override;
};

#endif // TOOLBARACTIONSCONTAINER_H
