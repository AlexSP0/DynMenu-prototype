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
    enum OnAllDisabledBehavior
    {
        Disable,
        Hide,
        Show
    };

public:
    IActionsContainer()          = default;
    virtual ~IActionsContainer() = default;

    virtual void setDefaultBehavior() = 0;

    virtual Command *addAction(QString actionName, QUuid group)    = 0;
    virtual Command *addMenu(IActionsContainer *menu, QUuid group) = 0;
    virtual Command *addSeparator(QUuid group)                     = 0;

    virtual QMenuBar *getMenu() = 0;

    virtual void deleteMenu(Command *menu)     = 0;
    virtual void deleteAction(Command *action) = 0;
};

#endif // IACTIONSCONTAINER_H
