#ifndef IACTIONSCONTAINER_H
#define IACTIONSCONTAINER_H

#include "command.h"

#include <QString>
#include <QUuid>
#include <qmenubar.h>

class IActionsContainer : public QObject
{
public:
    Q_OBJECT

public:
    IActionsContainer()          = default;
    virtual ~IActionsContainer() = default;

    virtual std::weak_ptr<Command> addAction(QAction *action, QUuid group)     = 0;
    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, QUuid group) = 0;
    virtual Command *addSeparator(QUuid group)                                 = 0;

    virtual QMenu *getMenu()       = 0;
    virtual QMenuBar *getMenuBar() = 0;
    virtual QUuid getId()          = 0;

    virtual bool deleteMenu(QUuid id)   = 0;
    virtual bool deleteAction(QUuid id) = 0;

public slots:
    virtual void destroyCommand(QObject *command) = 0;
    virtual void destroyMenu(QObject *command)    = 0;
};

#endif // IACTIONSCONTAINER_H
