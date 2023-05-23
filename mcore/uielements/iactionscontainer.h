#ifndef IACTIONSCONTAINER_H
#define IACTIONSCONTAINER_H

#include "../command.h"

#include <QString>
#include <QUuid>
#include <qmenubar.h>

/*!
 * \brief Container interface for QMenu and QActions classes
 *
 * All items (QMenuBar, QMenu, QToolBar(not implemented)) that have menus are wrapped in this
 * container implementing that interface. Containers can be nested. The
 * container does not own the wrappable items. If they are destroyed, the
 * corresponding slots are invoked and the item is removed from the container.
 *
 */

class IActionsContainer : public QObject
{
public:
    Q_OBJECT

public:
    IActionsContainer()          = default;
    virtual ~IActionsContainer() = default;

    /*!
    Adds a QAction object to the container.
    \param[in] action a pointer to the object to be added. The container does not own the object.
    \param[in] group group to which the object is added.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<Command> addAction(QAction *action, QUuid group) = 0;

    /*!
    Adds a QMenu object to the container. Returns the container for the added object.
    \param[in] menu action a pointer to the object to be added. The container does not own the object.
    \param[in] group group to which the object is added.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, QUuid group) = 0;

    /*!
    Adds a separator object to the container. Returns the container for the added object.
    \param[in] group group to which the object is added.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual Command *addSeparator(QUuid group) = 0;

    /*!
    Returns a pointer to the QMenu object placed in the container. If the pointer is of a different type, it returns nullptr
    \return pointer to QMenu object or nullptr
    */
    virtual QMenu *getMenu() = 0;

    /*!
    Returns a pointer to the QMenuBar object placed in the container. If the pointer is of a different type, it returns nullptr
    \return pointer to QMenuBar object or nullptr
    */
    virtual QMenuBar *getMenuBar() = 0;

    /*!
    Returns id of container
    \return id of container
    */
    virtual QUuid getId() = 0;

    /*!
    Returns a QAction container with the specified ID. If there is no object with this ID, it returns empty std::weak_ptr<>
    \param[in] id id of action container
    \return pointer to container or empty std::weak_ptr
    */
    virtual std::weak_ptr<Command> getActionById(QUuid id) = 0;

    /*!
    Returns a QMenu container with the specified ID. If there is no object with this ID, it returns empty std::weak_ptr<>
    \param[in] id id of menu container
    \return pointer to container or empty std::weak_ptr
    */
    virtual std::weak_ptr<IActionsContainer> getMenuById(QUuid id) = 0;

    /*!
    Sets the ID to the one specified in the parameter. Needed to set commonly used IDs for shared resources.
    \param[in] id ID to set up
    */
    virtual void setId(QUuid id) = 0;

    /*!
    Removes a QMenu object from the container with the specified ID.
    \param[in] id The ID of the object to be deleted
    \return returns true if successful and false if the object is not found.
    */
    virtual bool deleteMenu(QUuid id) = 0;

    /*!
    Removes a QAction object from the container with the specified ID.
    \param[in] id The ID of the object to be deleted
    \return returns true if successful and false if the object is not found.
    */
    virtual bool deleteAction(QUuid id) = 0;

public slots:

    /*!
    The slot removes a pointer to an object of type QAction from the container if the object is destroyed.
    */
    virtual void destroyCommand(QObject *command) = 0;

    /*!
    The slot removes a pointer to an object of type QMenu from the container if the object is destroyed.
    */
    virtual void destroyMenu(QObject *command) = 0;
};

#endif // IACTIONSCONTAINER_H
