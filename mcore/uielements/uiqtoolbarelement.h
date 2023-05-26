#ifndef UIQTOOLBARELEMENT_H
#define UIQTOOLBARELEMENT_H

#include "baseuielement.h"

class UiQToolBarElement : public BaseUiElement
{
public:
    UiQToolBarElement(QToolBar *toolBar);

    virtual ~UiQToolBarElement() = default;
    virtual void addAction(QAction *action) override;
    virtual void addMenu(QMenu *menu) override;
    virtual void removeAction(QAction *action) override;
    virtual void removeMenu(QMenu *menu) override;

    virtual QToolBar *getToolBar() override;

private:
    QToolBar *m_toolBar;
};

#endif // UIQTOOLBARELEMENT_H
