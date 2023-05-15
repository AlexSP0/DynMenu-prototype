#ifndef MENUACTIONSCONTAINER_H
#define MENUACTIONSCONTAINER_H

#include "baseactionscontainer.h"

class MenuActionsContainer : public BaseActionsContainer
{
public:
    MenuActionsContainer(QString title);

    virtual Command *addAction(QAction *action, QUuid group) override;
    virtual IActionsContainer *addMenu(QString title, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual bool deleteMenu(QUuid idu) override;
    virtual bool deleteAction(QUuid id) override;
};

#endif // MENUACTIONSCONTAINER_H
