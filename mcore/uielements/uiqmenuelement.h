#ifndef UIQMENUELEMENT_H
#define UIQMENUELEMENT_H

#include "baseuielement.h"

/*!
 * \brief The UiQMenuElement class container for QMenu object
 *
 * Container for an object of type QMenu. The container does not own the object. The container is deleted when the QMenu is destroyed.
 */
class UiQMenuElement : public BaseUiElement
{
public:
    UiQMenuElement(QMenu *menu);

    virtual ~UiQMenuElement() = default;

    /*!
     * \brief Adds QAction to QMenu object in the container
     * \param Pointer to QAction object
     */
    virtual void addAction(QAction *action) override;

    /*!
     * \brief Adds QMenu to QMenu object in the container
     * \param Pointer to QMenu object
     */
    virtual void addMenu(QMenu *menu) override;

    /*!
     * \brief Removes QAction to QMenu object in the container
     * \param Pointer to QAction object
     */
    virtual void removeAction(QAction *action) override;

    /*!
     * \brief Removes QMenu to QMenu object in the container
     * \param Pointer to QMenu object
     */
    virtual void removeMenu(QMenu *menu) override;

    /*!
     * \brief Return pointer to QMenu object in the container
     * \return pointer to QMenu object
     */
    virtual QMenu *getMenu() override;

private:
    QMenu *m_menu;
};

#endif // UIQMENUELEMENT_H
