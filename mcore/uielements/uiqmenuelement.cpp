#include "uiqmenuelement.h"

UiQMenuElement::UiQMenuElement(QMenu *menu)
    : m_menu(menu)
{}

void UiQMenuElement::addAction(QAction *action)
{
    m_menu->addAction(action);
}

void UiQMenuElement::addMenu(QMenu *menu)
{
    m_menu->addMenu(menu);
}

void UiQMenuElement::removeAction(QAction *action)
{
    m_menu->removeAction(action);
}

void UiQMenuElement::removeMenu(QMenu *menu)
{
    m_menu->removeAction(menu->menuAction());
}

QMenu *UiQMenuElement::getMenu()
{
    return m_menu;
}
