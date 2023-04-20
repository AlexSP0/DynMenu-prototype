#include "command.h"

Command::Command()
    : id(QUuid::createUuid())
{}

Command::Command(std::unique_ptr<QAction> currentAction)
    : id(QUuid::createUuid())
    , m_action(std::move(currentAction))
{}

Command::Command(std::unique_ptr<QMenu> currentMenu)
    : id(QUuid::createUuid())
    , m_menu(std::move(currentMenu))
{}

bool Command::operator==(const Command &other)
{
    return this->id == other.id;
}
