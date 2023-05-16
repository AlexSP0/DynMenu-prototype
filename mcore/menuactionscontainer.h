#ifndef BASEACTIONSCONTAINER_H
#define BASEACTIONSCONTAINER_H

#include <QObject>

#include <memory>

#include "iactionscontainer.h"
#include "ibasemenuactionscontainer.h"

class MenuActionsContainer : public IActionsContainer
{
public:
    MenuActionsContainer(QString title);
    virtual ~MenuActionsContainer();

    virtual Command *addAction(QAction *action, QUuid group) override;
    virtual IActionsContainer *addMenu(QString title, QUuid group) override;
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

    std::unique_ptr<QMenu> m_menu;
};

#endif // BASEACTIONSCONTAINER_H
