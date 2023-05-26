#ifndef IUIELEMENT_H
#define IUIELEMENT_H

#include "ibasemenuactionscontainer.h"
#include <QAction>
#include <QMenu>
#include <QToolBar>

/*!
 * \brief A container for GUI elements (QMenu, QMenuBar, QToolBar).
 *
 *  All container types for GUI items (QMenu, QMenuBar, QToolBar) must implement this interface.
 */

class IUiElement
{
public:
    virtual ~IUiElement() = default;

    /*!
     * \brief Adds action to ui element
     * \param action - pointer to QAction object
     */
    virtual void addAction(QAction *action) = 0;

    /*!
     * \brief Adds menu to ui element
     * \param menu - pointer to QMenu object
     */
    virtual void addMenu(QMenu *menu) = 0;

    /*!
     * \brief Removes action from ui element
     * \param action - pointer to QAction object
     */
    virtual void removeAction(QAction *action) = 0;

    /*!
     * \brief Removes menu from ui element
     * \param menu - pointer to QMenu object
     */
    virtual void removeMenu(QMenu *menu) = 0;

    /*!
     * \brief Returns a pointer to the QMenu object.
     * \return If the container contains an object of a different type, it returns nullptr.
     */
    virtual QMenu *getMenu() = 0;

    /*!
     * \brief Returns a pointer to the QMenuBar object.
     * \return If the container contains an object of a different type, it returns nullptr.
     */
    virtual QMenuBar *getMenuBar() = 0;

    /*!
     * \brief Returns a pointer to the QToolBar object.
     * \return If the container contains an object of a different type, it returns nullptr.
     */
    virtual QToolBar *getToolBar() = 0;

    /*!
     * \brief Sets a container to store objects of type IActionsContainer and Command.
     * \param Pointer to the container object
     */
    virtual void setContainer(IBaseMenuActionsContainer *container) = 0;
};

#endif
