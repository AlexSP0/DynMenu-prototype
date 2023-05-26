#ifndef IBASEMENUACTIONSCONTAINER_H
#define IBASEMENUACTIONSCONTAINER_H

#include <memory>
#include <vector>

#include "../command.h"
#include "iactionscontainer.h"

/*!
 * \brief Internal object that implements operations with stored containers of menus (IActionsContainer) and commands (Commands), Used by classes that implement the IActionsContainer interface.
 *
 * Interface for the class repository that implements the IActionsContainer interface.
 *
 */

class IBaseMenuActionsContainer
{
public:
    using CommandsMap = std::map<QUuid, std::shared_ptr<Command>>;
    using MenusMap    = std::map<QUuid, std::shared_ptr<IActionsContainer>>;

public:
    virtual ~IBaseMenuActionsContainer() = default;

    /*!
    Adds a QAction object to the storage.
    \param[in] action a pointer to the object to be added. The storage does not own the object.
    \param[in] group group to which the object is added.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::shared_ptr<Command> appendAction(QAction *action) = 0;

    /*!
    Adds a QMenu object to the storage.
    \param[in] QMenu a pointer to the object to be added. The storage does not own the object.
    \param[in] group group to which the object is added.
    \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::shared_ptr<IActionsContainer> appendMenu(QMenu *menu) = 0;

    /*!
    Removes a QMenu container from the storage with the specified ID.
    \param[in] id The ID of the container to be deleted
    \return returns true if successful and false if the object is not found.
    */
    virtual bool removeAction(QUuid id) = 0;

    /*!
    Removes a QAction container from the storage with the specified ID.
    \param[in] id The ID of the container to be deleted
    \return returns true if successful and false if the object is not found.
    */
    virtual bool removeMenu(QUuid id) = 0;

    /*!
    Return std::map with commands containers(QActions).
    \return std::map with QActions containers
    */
    virtual CommandsMap &getActions() = 0;

    /*!
    Return std::map with IACtionsContainer containers(QMenu).
    \return std::map with QMenu containers
    */
    virtual MenusMap &getMenus() = 0;

    /*!
    Returns a QAction container with the specified ID. If there is no object with this ID, it returns empty std::weak_ptr<>
    \param[in] id id of action container
    \return pointer to container or empty std::weak_ptr
    */
    virtual std::shared_ptr<Command> getActionContainer(QUuid id) = 0;

    /*!
    Returns a QMenu container with the specified ID. If there is no object with this ID, it returns empty std::weak_ptr<>
    \param[in] id id of menu container
    \return pointer to container or empty std::weak_ptr
    */
    virtual std::shared_ptr<IActionsContainer> getMenuContainer(QUuid id) = 0;

    /*!
    Returns a pointer to QActions container with the specified pointer. If there is no object with this ID, it returns nullptr
    \param[in] action pointer to QAction
    \return pointer to container or nullptr
    */
    virtual Command *getActionContainerByPtr(QObject *action) = 0;

    /*!
    Returns a pointer to QMenu container with the specified pointer. If there is no object with this ID, it returns nullptr
    \param[in] menu pointer to QMenu
    \return pointer to container or nullptr
    */
    virtual IActionsContainer *getMenuContainerByPtr(QObject *menu) = 0;
};

#endif // IBASEMENUACTIONSCONTAINER_H
