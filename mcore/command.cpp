#include "command.h"

Command::Command()
    : id(QUuid::createUuid())
{}

Command::Command(std::shared_ptr<QAction> currentAction)
    : id(QUuid::createUuid())
    , m_action(currentAction)
    , m_defaultText(id.toString())
{}

Command::Command(std::shared_ptr<QMenu> currentMenu)
    : id(QUuid::createUuid())
    , m_menu(currentMenu)
    , m_defaultText(id.toString())
{}

bool Command::operator==(const Command &other)
{
    return this->id == other.id;
}

QAction *Command::getAction()
{
    if (m_action)
    {
        return m_action.get();
    }
    if (m_menu)
    {
        return m_menu->menuAction();
    }
    return nullptr;
}
