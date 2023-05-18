#ifndef UIQMENUBARELEMENT_H
#define UIQMENUBARELEMENT_H

#include "uielements/baseuielement.h"

class UiQMenuBarElement : public BaseUiElement
{
public:
    UiQMenuBarElement(QMenuBar *menuBar);

    virtual ~UiQMenuBarElement() = default;

    virtual void addAction(QAction *action) override;
    virtual void addMenu(QMenu *menu) override;

    virtual void removeAction(QAction *action) override;
    virtual void removeMenu(QMenu *menu) override;

    virtual QMenuBar *getMenuBar() override;

private:
    QMenuBar *m_menuBar;
};

#endif // UIQMENUBARELEMENT_H
