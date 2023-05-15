#include "command.h"

Command::Command(QAction *action)
    : m_id(QUuid::createUuid())
    , m_action(action)
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
    return m_action;
}

QString &Command::getText()
{
    return m_text;
}

void Command::setText(QString text)
{
    m_text = text;
}
