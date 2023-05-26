#ifndef UICONTAINER_H
#define UICONTAINER_H

#include "iactionscontainer.h"
#include "ibasemenuactionscontainer.h"

#include "iuielement.h"

#include <QMenuBar>

/*!
 * \brief The This is a container for objects of type IUIElement and content for objects of type Command and IActionsContainer.
 *
 * Defines the interaction between objects of type IUIElement (container for GUI element) and containers of type Command and IActionsContainer.
 */

class UiContainer : public IActionsContainer
{
    UiContainer();

public:
    UiContainer(QMenu *menu);
    UiContainer(QMenuBar *menuBar);
    UiContainer(QToolBar *toolbar);

    virtual ~UiContainer();
    /*!
    * Adds a QAction object to the container. Groups are NOT implemented.
    * \param[in] action a pointer to the object to be added. The container does not own the object.
    * \param[in] group group to which the object is added.
    * \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<Command> addAction(QAction *action, QUuid group);

    /*!
    Adds a QMenu object to the container. Returns the container for the added object. Groups are NOT implemented.
    * \param[in] menu action a pointer to the object to be added. The container does not own the object.
    * \param[in] group group to which the object is added.
    * \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, QUuid group);

    /*!
    * Adds a separator object to the container. Returns the container for the added object. NOT Implemented
    * \param[in] group group to which the object is added.
    * \return Returns the container to the object to be added if it was added successfully. In case of error it returns empty std::weak_ptr<>.
    */
    virtual Command *addSeparator(QUuid group);

    /*!
    * Returns a pointer to the QMenu object placed in the container. If the pointer is of a different type, it returns nullptr
    * \return pointer to QMenu object or nullptr
    */
    virtual QMenu *getMenu() override;

    /*!
    * Returns a pointer to the QMenuBar object placed in the container. If the pointer is of a different type, it returns nullptr
    * \return pointer to QMenuBar object or nullptr
    */
    virtual QMenuBar *getMenuBar() override;

    /*!
    * Returns a pointer to the QToolBar object placed in the container. If the pointer is of a different type, it returns nullptr
    * \return pointer to QToolBar object or nullptr
    */
    QToolBar *getToolBar();

    /*!
    * Returns a QAction container with the specified ID. If there is no object with this ID, it returns empty std::weak_ptr<>
    * \param[in] id id of action container
    * \return pointer to container or empty std::weak_ptr
    */
    virtual std::weak_ptr<Command> getActionById(QUuid id) override;

    /*!
    * Returns a QMenu container with the specified ID. If there is no object with this ID, it returns empty std::weak_ptr<>
    * \param[in] id id of menu container
    * \return pointer to container or empty std::weak_ptr
    */
    std::weak_ptr<IActionsContainer> getMenuById(QUuid id) override;

    /*!
    * Returns id of container
    * \return id of container
    */
    virtual QUuid getId();

    /*!
    * Sets the ID to the one specified in the parameter. Needed to set commonly used IDs for shared resources.
    * \param[in] id ID to set up
    */
    void setId(QUuid id);

    /*!
    * Removes a QMenu object from the container with the specified ID.
    * \param[in] id The ID of the object to be deleted
    * \return returns true if successful and false if the object is not found.
    */
    virtual bool deleteMenu(QUuid id);

    /*!
    * Removes a QAction object from the container with the specified ID.
    * \param[in] id The ID of the object to be deleted
    * \return returns true if successful and false if the object is not found.
    */
    virtual bool deleteAction(QUuid id);

private slots:
    virtual void destroyCommand(QObject *command);
    virtual void destroyMenu(QObject *menu);

private:
    QUuid m_id;

    IBaseMenuActionsContainer *m_container;

    IUiElement *m_element;
};

#endif
