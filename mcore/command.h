#ifndef COMMAND_H
#define COMMAND_H

#include <QAction>
#include <QMenu>
#include <QUuid>

#include <memory>

class Command
{
public:
    Command();

    Command(std::unique_ptr<QAction> currentAction);

    Command(std::unique_ptr<QMenu> currentAction);

    bool operator==(const Command &other);

public:
    QUuid id;

    std::unique_ptr<QAction> m_action = nullptr;

    std::unique_ptr<QMenu> m_menu = nullptr;

    QString defaultText = "";

    //TO DO add QKeySequence, QIcon and etc
};

#endif // COMMAND_H
