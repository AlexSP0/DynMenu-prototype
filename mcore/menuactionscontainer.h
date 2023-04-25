#ifndef MENUACTIONSCONTAINER_H
#define MENUACTIONSCONTAINER_H

#include "baseactionscontainer.h"

class MenuActionsContainer : public BaseActionsContainer
{
public:
    MenuActionsContainer(QMenuBar *menuBar);

    virtual Command *addAction(QString actionName, QUuid group) override;
    virtual Command *addMenu(IActionsContainer *menu, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual void deleteMenu(Command *menu) override;
    virtual void deleteAction(Command *action) override;
};

#endif // MENUACTIONSCONTAINER_H
