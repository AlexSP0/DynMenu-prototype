#ifndef IUIELEMENT_H
#define IUIELEMENT_H

#include "../ibasemenuactionscontainer.h"
#include <QAction>
#include <QMenu>

class IUiElement
{
public:
    virtual ~IUiElement() = default;

    virtual void addAction(QAction *action) = 0;
    virtual void addMenu(QMenu *menu)       = 0;

    virtual void removeAction(QAction *action) = 0;
    virtual void removeMenu(QMenu *menu)       = 0;

    virtual QMenu *getMenu()       = 0;
    virtual QMenuBar *getMenuBar() = 0;

    virtual void setContainer(IBaseMenuActionsContainer *container) = 0;
};

#endif
