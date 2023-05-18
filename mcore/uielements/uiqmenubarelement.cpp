#include "uiqmenubarelement.h"

UiQMenuBarElement::UiQMenuBarElement(QMenuBar *menuBar)
    : m_menuBar(menuBar)
{}

void UiQMenuBarElement::addAction(QAction *action)
{
    m_menuBar->addAction(action);
}

void UiQMenuBarElement::addMenu(QMenu *menu)
{
    m_menuBar->addMenu(menu);
}

void UiQMenuBarElement::removeAction(QAction *action)
{
    m_menuBar->removeAction(action);
}

void UiQMenuBarElement::removeMenu(QMenu *menu)
{
    m_menuBar->removeAction(menu->menuAction());
}

QMenuBar *UiQMenuBarElement::getMenuBar()
{
    return m_menuBar;
}
