#ifndef COMMAND_H
#define COMMAND_H

#include <QAction>
#include <QMenu>
#include <QObject>
#include <QUuid>

#include <memory>

class Command : public QObject
{
public:
    Q_OBJECT
public:
    Command(QAction *action);

    QUuid getId();

    bool operator==(const Command &other);

    QAction *getAction();

    QString &getText();

    void setText(QString text);

    //TO DO hide all member and write getters
private:
    QUuid m_id;

    QAction *m_action;

    QString m_text = "";

    //TO DO add QKeySequence, QIcon and etc
};

#endif // COMMAND_H
