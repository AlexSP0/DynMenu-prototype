#ifndef UIQMENUELEMENT_H
#define UIQMENUELEMENT_H

#include "baseuielement.h"

class UiQMenuElement : public BaseUiElement
{
public:
    UiQMenuElement(QMenu *menu);

    virtual ~UiQMenuElement() = default;

    virtual void addAction(QAction *action) override;
    virtual void addMenu(QMenu *menu) override;

    virtual void removeAction(QAction *action) override;
    virtual void removeMenu(QMenu *menu) override;

    virtual QMenu *getMenu() override;

private:
    QMenu *m_menu;
};

#endif // UIQMENUELEMENT_H
