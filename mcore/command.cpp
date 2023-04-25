#include "command.h"

Command::Command(QAction *action)
    : m_id(QUuid::createUuid())
    , m_action(action)
    , m_menu(nullptr)
    , m_text(m_id.toString())
{}

Command::Command(QMenu *menu)
    : m_id(QUuid::createUuid())
    , m_action(nullptr)
    , m_menu(menu)
    , m_text(m_id.toString())
{}

QUuid Command::getId()
{
    return m_id;
}

bool Command::operator==(const Command &other)
{
    return this->m_id == other.m_id;
}

QAction *Command::getAction()
{
    if (m_action)
    {
        return m_action;
    }
    if (m_menu)
    {
        return m_menu->menuAction();
    }
    return nullptr;
}

QMenu *Command::getMenu()
{
    return m_menu;
}

QString &Command::getText()
{
    return m_text;
}

void Command::setText(QString &text)
{
    m_text = text;
}
