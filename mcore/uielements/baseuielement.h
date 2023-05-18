#ifndef BASEUIELEMENT_H
#define BASEUIELEMENT_H

#include "iuielement.h"

class BaseUiElement : public IUiElement
{
public:
    BaseUiElement();
    virtual ~BaseUiElement() = default;

    virtual void addAction(QAction *action) override;
    virtual void addMenu(QMenu *menu) override;

    virtual void removeAction(QAction *action) override;
    virtual void removeMenu(QMenu *menu) override;

    virtual void setContainer(IBaseMenuActionsContainer *container) override;

    virtual QMenu *getMenu() override;
    virtual QMenuBar *getMenuBar() override;

protected:
    IBaseMenuActionsContainer *m_container;
};

#endif // BASEUIELEMENT_H
