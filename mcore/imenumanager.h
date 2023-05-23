#ifndef IMENUMANAGER_H
#define IMENUMANAGER_H

#include "imenumanageablewindow.h"
#include "uielements/iactionscontainer.h"

#include <QString>
#include <QToolBar>
#include <QUuid>

/*!
 * \brief Interface for menu manager
 *
 * Interface for registering objects containing menus and creating menus and commands in them
 *
 */

class IMenuManager : public QObject
{
public:
    Q_OBJECT
public:
    using ContainerMap = std::map<QUuid, std::shared_ptr<IActionsContainer>>;

    IMenuManager()          = default;
    virtual ~IMenuManager() = default;

    /*!
    Adds a QMenu object to container (QMenuBar, QMenu, QToolBar)
    \param[in] menu a pointer to the QMenu object to be added. The container does not own the object.
    \param[in] container a container? where QMenu will be added
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, IActionsContainer *container) = 0;

    /*!
    Delete a QMenu object from container (QMenuBar, QMenu, QToolBar)
    \param[in] menu a container with specified menu
    \param[in] container a container? where QMenu will be added
    \return Returns true if successful and false if the object is not found.
    */
    virtual bool deleteMenu(IActionsContainer *menu, IActionsContainer *container) = 0;

    /*!
    Returns a QMenu container with the specified ID. If there is no object with this ID, it returns empty std::weak_ptr<>
    \param[in] id id of menu container
    \return pointer to container or empty std::weak_ptr
    */
    virtual std::weak_ptr<IActionsContainer> getMenu(QUuid id) = 0;

    /*!
    Adds a QAction object to container (QMenuBar, QMenu, QToolBar)
    \param[in] action a pointer to the QAction object to be added. The container does not own the object.
    \param[in] container a container? where QAction will be added
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<Command> addAction(QAction *action, IActionsContainer *container) = 0;

    /*!
    Delete a QAction object from container (QMenuBar, QMenu, QToolBar)
    \param[in] action a container with specified action
    \param[in] container a container? where QAction will be added
    \return Returns true if successful and false if the object is not found.
    */
    virtual bool deleteAction(IActionsContainer *action, IActionsContainer *container) = 0;

    /*!
    Returns a QAction container with the specified ID. If there is no object with this ID, it returns empty std::weak_ptr<>
    \param[in] id id of actions container
    \return pointer to container or empty std::weak_ptr
    */
    virtual std::weak_ptr<Command> getAction(QUuid id, IActionsContainer *container) = 0;

    /*!
    Registers an object of type QMenuBar for later adding menus(QMenu) and action(QAction) to it
    \param[in] menuBar a pointer to the QMenuBar object to be added. The container does not own the object.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<IActionsContainer> registerMenuBar(QMenuBar *menuBar) = 0;

    /*!
    Registers an object of type QMenu for later adding menus(QMenu) and action(QAction) to it
    \param[in] menu a pointer to the QMenu object to be added. The container does not own the object.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<IActionsContainer> registerMenu(QMenu *menu) = 0;

    /*!
    Registers an object of type QToolBar for later adding menus(QMenu) and action(QAction) to it
    \param[in] toolbar a pointer to the QToolBar object to be added. The container does not own the object.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<IActionsContainer> registerToolBar(QToolBar toolbar) = 0;

    /*!
    Unregisters an object of type QMenuBar.
    \param[in] menuBar a pointer to the QMenuBar container object to be deleted
    \return returns true if successful and false if the object is not found.
    */
    virtual bool unRegisterMenuBar(IActionsContainer *menuBar) = 0;

    /*!
    Unregisters an object of type QMenu.
    \param[in] menu a pointer to the QMenu container object to be deleted
    \return returns true if successful and false if the object is not found.
    */
    virtual bool unRegisterMenu(IActionsContainer *menu) = 0;

    /*!
    Unregisters an object of type toolbar.
    \param[in]  toolbar a pointer to the QToolBar container object to be deleted
    \return returns true if successful and false if the object is not found.
    */
    virtual bool unRegisterToolBar(IActionsContainer *toolbar) = 0;

public slots:
    /*!
    The slot removes a pointer to an object of type QMenuBar from the container if the object is destroyed.
    */
    virtual void menuBarDestroyed(QObject *menuBar) = 0;

    /*!
    The slot removes a pointer to an object of type QMenu from the container if the object is destroyed.
    */
    virtual void menuDestroyed(QObject *menu) = 0;

    /*!
    The slot removes a pointer to an object of type QToolBar from the container if the object is destroyed.
    */
    virtual void toolBarDestroyed(QObject *toolBar) = 0;
};

#endif // IMENUMANAGER_H
