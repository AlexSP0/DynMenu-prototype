#ifndef IMENUMANAGER_H
#define IMENUMANAGER_H

#include "iactionscontainer.h"

#include <QString>
#include <QUuid>

class IMenuManager : public QObject
{
public:
    Q_OBJECT
public:
    IMenuManager()          = default;
    virtual ~IMenuManager() = default;

    virtual IActionsContainer *createMenu(QString &menuName, QUuid group) = 0;
    virtual bool deleteMenu(IActionsContainer *menuContainer)             = 0;

    virtual QUuid registerWindow(QWidget *window)  = 0;
    virtual bool unregisterWindow(QUuid *windowId) = 0;
};

#endif // IMENUMANAGER_H
