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

    Command(std::shared_ptr<QAction> currentAction);

    Command(std::shared_ptr<QMenu> currentAction);

    bool operator==(const Command &other);

    QAction *getAction();

    //TO DO hide all member and write getters
public:
    QUuid id;

    std::shared_ptr<QAction> m_action = nullptr;

    std::shared_ptr<QMenu> m_menu = nullptr;

    QString m_defaultText = "";

    //TO DO add QKeySequence, QIcon and etc
};

#endif // COMMAND_H
