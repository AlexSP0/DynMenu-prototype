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

    /*!
     * \brief Adds action to ui element
     * \param action - pointer to QAction object
     */
    virtual void addAction(QAction *action) override;

    /*!
     * \brief Adds menu to ui element
     * \param menu - pointer to QMenu object
     */
    virtual void addMenu(QMenu *menu) override;

    /*!
     * \brief Removes action from ui element
     * \param action - pointer to QAction object
     */
    virtual void removeAction(QAction *action) override;

    /*!
     * \brief Removes menu from ui element
     * \param menu - pointer to QMenu object
     */
    virtual void removeMenu(QMenu *menu) override;

    /*!
     * \brief Returns a pointer to the QMenu object.
     * \return If the container contains an object of a different type, it returns nullptr.
     */
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

    /*!
    * Returns pointer to QToolBar object
    * In this implementation return nullptr
    */
    virtual QToolBar *getToolBar() override;

protected:
    IBaseMenuActionsContainer *m_container;
};

#endif // BASEUIELEMENT_H
