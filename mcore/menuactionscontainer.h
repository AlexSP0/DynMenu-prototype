#ifndef BASEACTIONSCONTAINER_H
#define BASEACTIONSCONTAINER_H

#include <QObject>

#include <memory>

#include "iactionscontainer.h"
#include "ibasemenuactionscontainer.h"

class MenuActionsContainer : public IActionsContainer
{
public:
    MenuActionsContainer(QMenu *menu);
    virtual ~MenuActionsContainer();

    virtual std::shared_ptr<Command> addAction(QAction *action, QUuid group) override;
    virtual std::shared_ptr<IActionsContainer> addMenu(QMenu *menu, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;

    virtual QUuid getId() override;

    QMenu *getMenu() override;

    virtual bool deleteMenu(QUuid id) override;
    virtual bool deleteAction(QUuid id) override;

private slots:
    void destroyCommand(QObject *command);
    void destroyMenu(QObject *command);

private:
    QUuid m_id;

    IBaseMenuActionsContainer *m_container;

    QMenu *m_menu;
};

#endif // BASEACTIONSCONTAINER_H
