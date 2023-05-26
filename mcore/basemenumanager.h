#ifndef BASEMENUMANAGER_H
#define BASEMENUMANAGER_H

#include "imenumanager.h"

#include "uielements/uicontainer.h"

/*!
 * \brief Interface for menu manager
 *
 * Implements IMenuManager. Class for registering objects containing menus and creating menus and commands in them
 *
 */

class BaseMenuManager : public IMenuManager
{
public:
    BaseMenuManager();
    virtual ~BaseMenuManager();

    /*!
    Adds a QMenu object to container (QMenuBar, QMenu, QToolBar)
    \param[in] menu a pointer to the QMenu object to be added. The container does not own the object.
    \param[in] container a container? where QMenu will be added
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, IActionsContainer *container) override;

    /*!
    Delete a QMenu object from container (QMenuBar, QMenu, QToolBar)
    \param[in] menu a container with specified menu
    \param[in] container a container? where QMenu will be added
    \return Returns true if successful and false if the object is not found.
    */
    bool deleteMenu(IActionsContainer *menu, IActionsContainer *container) override;

    /*!
    Returns a QMenu container with the specified ID. If there is no object with this ID, it returns empty std::weak_ptr<>
    \param[in] id id of menu container
    \return pointer to container or empty std::weak_ptr
    */
    std::weak_ptr<IActionsContainer> getMenu(QUuid id) override;

    /*!
    Adds a QAction object to container (QMenuBar, QMenu, QToolBar)
    \param[in] action a pointer to the QAction object to be added. The container does not own the object.
    \param[in] container a container? where QAction will be added
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<Command> addAction(QAction *action, IActionsContainer *container) override;

    /*!
    Delete a QAction object from container (QMenuBar, QMenu, QToolBar)
    \param[in] action a container with specified action
    \param[in] container a container? where QAction will be added
    \return Returns true if successful and false if the object is not found.
    */
    virtual bool deleteAction(IActionsContainer *action, IActionsContainer *container) override;

    /*!
    Returns a QAction container with the specified ID. If there is no object with this ID, it returns empty std::weak_ptr<>
    \param[in] id id of actions container
    \return pointer to container or empty std::weak_ptr
    */
    std::weak_ptr<Command> getAction(QUuid id, IActionsContainer *container) override;

    /*!
    Registers an object of type QMenuBar for later adding menus(QMenu) and action(QAction) to it
    \param[in] menuBar a pointer to the QMenuBar object to be added. The container does not own the object.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<IActionsContainer> registerMenuBar(QMenuBar *menuBar) override;

    /*!
    Registers an object of type QMenu for later adding menus(QMenu) and action(QAction) to it
    \param[in] menu a pointer to the QMenu object to be added. The container does not own the object.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<IActionsContainer> registerMenu(QMenu *menu) override;

    /*!
    Registers an object of type QToolBar for later adding menus(QMenu) and action(QAction) to it
    \param[in] toolbar a pointer to the QToolBar object to be added. The container does not own the object.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<IActionsContainer> registerToolBar(QToolBar *toolbar) override;

    /*!
    Unregisters an object of type QMenuBar.
    \param[in] menuBar a pointer to the QMenuBar container object to be deleted
    \return returns true if successful and false if the object is not found.
    */
    virtual bool unRegisterMenuBar(IActionsContainer *menuBar) override;

    /*!
    Unregisters an object of type QMenu.
    \param[in] menu a pointer to the QMenu container object to be deleted
    \return returns true if successful and false if the object is not found.
    */
    virtual bool unRegisterMenu(IActionsContainer *menu) override;

    /*!
    Unregisters an object of type toolbar.
    \param[in]  toolbar a pointer to the QToolBar container object to be deleted
    \return returns true if successful and false if the object is not found.
    */
    virtual bool unRegisterToolBar(IActionsContainer *toolbar) override;

    /*!
     * \brief Returns menu container with specified Id
     * \param id specified Id
     * \return return pointer to menu container if successful, or empty std::weak_ptr<> if menu not found
     */
    std::weak_ptr<IActionsContainer> getMenuById(QUuid id);

    /*!
     * \brief Returns action container with specified Id
     * \param id specified Id
     * \return return pointer to action container if successful, or empty std::weak_ptr<> if menu not found
     */
    std::weak_ptr<Command> getActionById(QUuid id, IActionsContainer *containerId);

public slots:
    virtual void menuBarDestroyed(QObject *menuBar) override;
    virtual void menuDestroyed(QObject *menu) override;
    virtual void toolBarDestroyed(QObject *toolBar) override;

private:
    ContainerMap m_containersMap;
};

#endif // BASEMENUMANAGER_H
