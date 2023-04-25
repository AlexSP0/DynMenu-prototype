#ifndef CONTEXTMENUACTIONSCONTAINER_H
#define CONTEXTMENUACTIONSCONTAINER_H

#include "baseactionscontainer.h"

class ContextMenuActionsContainer : public BaseActionsContainer
{
public:
    ContextMenuActionsContainer(QMenuBar *menuBar);

    virtual Command *addAction(QString actionName, QUuid group) override;
    virtual Command *addMenu(IActionsContainer *menu, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual void deleteMenu(Command *menu) override;
    virtual void deleteAction(Command *action) override;
};

#endif // CONTEXTMENUACTIONSCONTAINER_H
