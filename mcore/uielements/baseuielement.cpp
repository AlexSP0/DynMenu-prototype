#include "baseuielement.h"

BaseUiElement::BaseUiElement() {}

void BaseUiElement::addAction(QAction *action) {}

void BaseUiElement::addMenu(QMenu *menu) {}

void BaseUiElement::removeAction(QAction *action) {}

void BaseUiElement::removeMenu(QMenu *menu) {}

void BaseUiElement::setContainer(IBaseMenuActionsContainer *container)
{
    m_container = container;
}

QMenu *BaseUiElement::getMenu()
{
    return nullptr;
}

QMenuBar *BaseUiElement::getMenuBar()
{
    return nullptr;
}
