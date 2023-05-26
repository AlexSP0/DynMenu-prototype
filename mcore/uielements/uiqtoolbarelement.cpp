#include "uiqtoolbarelement.h"

UiQToolBarElement::UiQToolBarElement(QToolBar *toolBar)
    : m_toolBar(toolBar)
{}

void UiQToolBarElement::addAction(QAction *action)
{
    m_toolBar->addAction(action);
}

void UiQToolBarElement::addMenu(QMenu *menu)
{
    m_toolBar->addAction(menu->menuAction());
}

void UiQToolBarElement::removeAction(QAction *action)
{
    m_toolBar->removeAction(action);
}

void UiQToolBarElement::removeMenu(QMenu *menu)
{
    removeAction(menu->menuAction());
}

QToolBar *UiQToolBarElement::getToolBar()
{
    return m_toolBar;
}
