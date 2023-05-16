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

    virtual Command *addAction(QAction *action, QUuid group)       = 0;
    virtual IActionsContainer *addMenu(QString title, QUuid group) = 0;
    virtual Command *addSeparator(QUuid group)                     = 0;

    virtual QMenu *getMenu() = 0;
    virtual QUuid getId()    = 0;

    virtual bool deleteMenu(QUuid id)   = 0;
    virtual bool deleteAction(QUuid id) = 0;
};

#endif // IACTIONSCONTAINER_H
