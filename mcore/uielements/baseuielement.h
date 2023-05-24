#ifndef BASEUIELEMENT_H
#define BASEUIELEMENT_H

#include "iuielement.h"

/*!
 * \brief a base class for all uielements (for IActionsContainer).
 *
 * A base class for all classes to implement the IActionContainer interface.
 * The getMenu() and getMenuBar methods return nullptr.
 *
 */

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

    /*!
    * Returns pointer to QMenu object
    * In this implementation return nullptr
    */
    virtual QMenu *getMenu() override;

    /*!
    * Returns pointer to QMenuBar object
    * In this implementation return nullptr
    */
    virtual QMenuBar *getMenuBar() override;

protected:
    IBaseMenuActionsContainer *m_container;
};

#endif // BASEUIELEMENT_H
