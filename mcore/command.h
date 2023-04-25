#ifndef COMMAND_H
#define COMMAND_H

#include <QAction>
#include <QMenu>
#include <QUuid>

#include <memory>

class Command
{
public:
    Command(QAction *action);

    Command(QMenu *menu);

    QUuid getId();

    bool operator==(const Command &other);

    QAction *getAction();

    QMenu *getMenu();

    QString &getText();

    void setText(QString &text);

    //TO DO hide all member and write getters
private:
    QUuid m_id;

    QAction *m_action;

    QMenu *m_menu;

    QString m_text = "";

    //TO DO add QKeySequence, QIcon and etc
};

#endif // COMMAND_H
