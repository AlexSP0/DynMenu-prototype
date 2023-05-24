#ifndef UIQMENUBARELEMENT_H
#define UIQMENUBARELEMENT_H

#include "uielements/baseuielement.h"
/*!
 * \brief The UiQMenuBarElement class container for QMenu object
 *
 * Container for an object of type QMenuBar. The container does not own the object. The container is deleted when the QMenu is destroyed.
 */
class UiQMenuBarElement : public BaseUiElement
{
public:
    UiQMenuBarElement(QMenuBar *menuBar);

    virtual ~UiQMenuBarElement() = default;

    /*!
     * \brief Adds QAction to QMenuBar object in the container
     * \param Pointer to QAction object
     */
    virtual void addAction(QAction *action) override;

    /*!
     * \brief Adds QMenu to QMenuBar object in the container
     * \param Pointer to QMenu object
     */
    virtual void addMenu(QMenu *menu) override;

    /*!
     * \brief Removes QAction to QMenuBar object in the container
     * \param Pointer to QAction object
     */
    virtual void removeAction(QAction *action) override;

    /*!
     * \brief Removes QMenu to QMenuBar object in the container
     * \param Pointer to QMenu object
     */
    virtual void removeMenu(QMenu *menu) override;

    /*!
     * \brief Return pointer to QMenuBar object in the container
     * \return pointer to QMenuBar object
     */
    virtual QMenuBar *getMenuBar() override;

private:
    QMenuBar *m_menuBar;
};

#endif // UIQMENUBARELEMENT_H
