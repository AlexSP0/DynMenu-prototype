#ifndef BASEACTIONSCONTAINER_H
#define BASEACTIONSCONTAINER_H

#include <QObject>

#include <memory>

#include "iactionscontainer.h"

class BaseActionsContainer : public IActionsContainer
{
public:
    BaseActionsContainer(QString title);
    virtual ~BaseActionsContainer();

    OnAllDisabledBehavior getAllDisableBehavior();

    virtual void setDefaultBehavior() override;

    virtual Command *addAction(QAction *action, QUuid group) override;
    virtual IActionsContainer *addMenu(QString title, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;

    virtual QUuid getId() override;

    QMenu *getMenu();

    virtual bool deleteMenu(QUuid id) override;
    virtual bool deleteAction(QUuid id) override;

protected:
    bool appendAction(std::shared_ptr<Command> command, QUuid group);
    bool removeAction(QUuid id);

    bool appendMenu(std::shared_ptr<IActionsContainer> menu, QUuid group);
    bool removeMenu(QUuid id);

private slots:
    void destroyCommand(QObject *command);
    void destroyMenu(QObject *command);

private:
    QUuid m_id;
    std::unique_ptr<QMenu> m_menu;
    std::map<QUuid, std::shared_ptr<Command>> m_actions;
    std::map<QUuid, std::shared_ptr<IActionsContainer>> m_menus;

    OnAllDisabledBehavior m_disableBehavior;
};

#endif // BASEACTIONSCONTAINER_H
