#ifndef TOOLBARACTIONSCONTAINER_H
#define TOOLBARACTIONSCONTAINER_H

#include "baseactionscontainer.h"

class ToolBarActionsContainer : public BaseActionsContainer
{
public:
    ToolBarActionsContainer(QMenuBar *menuBar);

    virtual Command *addAction(QString actionName, QUuid group) override;
    virtual Command *addMenu(IActionsContainer *menu, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual void deleteMenu(Command *menu) override;
    virtual void deleteAction(Command *action) override;
};

#endif // TOOLBARACTIONSCONTAINER_H
